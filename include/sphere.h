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
        float3 albedo; // color 0-1, 0-1, 0-1
        float  radius;
        bool   mirror;

        Sphere(float3 center, 
               float3 albedo,
               float  radius,
               bool   mirror) : 
               center(center), 
               radius(radius),
               albedo(albedo),
               mirror(mirror) { }

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
    if (delta > 0) {
        ret.hit = true;
        float t1 = (-b - std::sqrt(delta)) / 2.0f*a; 
        float t2 = (-b + std::sqrt(delta)) / 2.0f*a;
        float t;
        float length1 = ray.at(t1).lenght();
        float length2 = ray.at(t2).lenght();
        if (length1 <= length2) {
            ret.length_ray = length1;
            t = t1;
        } else {
            ret.length_ray = length2;
            t = t2;
        }
        ret.hit_point = ray.at(t);
        ret.normal = (ret.hit_point - center).get_normalize();
        if (ray.direction * (ret.hit_point - ray.origin) <= 0) {
            // if the ray hit the sphere in the opposite direction
            ret.hit = false;
        }
        if (ray.direction * ret.normal > 0) {
            // if the ray hit the sphere in the inside
            ret.hit = false;
        }
        ret.hit_sphere = (void*)this;
    }
    return ret;
}

#endif