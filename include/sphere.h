#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <cmath>
#include "float3.h"
#include "ray.h"

struct HasHit {
    bool    hit;
    float3  hit_point;
    float3  normal;
    float   length_ray;
    void*   hit_sphere;
};

class Sphere {

    public:
        float3 center;
        float  radius;

        Sphere(float3 center, float radius) : 
            center(center), radius(radius) {}

        HasHit hasHit(Ray& ray);

};

inline HasHit Sphere::hasHit(Ray& ray) {
    HasHit ret;
    ret.hit = false;
    float3 A = ray.origin;
    float3 B = ray.direction;
    float3 C = center;
    float  r = radius;
    float  a = B * B;
    float  b = 2 * (B * (A - C));
    float  c = ((A - C)*(A - C)) - r * r; 
    float  delta = b * b - 4 * a * c;
    if (delta >= 0) {
        float t1 = (-b - std::sqrt(delta)) / 2*a; 
        float t2 = (-b + std::sqrt(delta)) / 2*a;
        float t;
        float length1 = ray.at(t1).lenght();
        float length2 = ray.at(t2).lenght();
        if (length1 <= length2) {
            t = t1;
            ret.length_ray = length1;
        } else {
            t = t2;
            ret.length_ray = length2;
        }
        ret.hit = true;
        ret.hit_point = ray.at(t);
        ret.normal = (ret.hit_point - center).get_normalize();
        ret.hit_sphere = this;
    }
    return ret;
}

#endif