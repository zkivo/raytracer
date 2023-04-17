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

    /*
        The Sphere absorb ligth internally (attenuation)
            the rest is reflected.
        Diffuse contains how much ligth is diffused interpotated with albedo
        Mirror contains how much ligth is reflected
    */

    public:
        float3 center;
        float3 albedo; // color
        float  attenuation; // 0-1
        float  albedo_diffuse; // 0-1
        float  sky_diffuse; // 0-1
        float  mirror_reflection; // 0-1
        float  radius;

        Sphere(float3 center, 
               float radius,
               float3 albedo,
               float attenuation,
               float albedo_diffuse,
               float sky_diffuse,
               float mirror_reflection) : 
               center(center), 
               radius(radius),
               albedo(albedo) {
            // float reflectance = 1.0f - attenuation;
            // this->mirror_reflection = mirror_reflection / reflectance;
            // this->albedo_diffuse = albedo_diffuse / (albedo_diffuse + sky_diffuse) * reflectance;
            // this->sky_diffuse    = sky_diffuse / (albedo_diffuse + sky_diffuse) * reflectance;
            float sum = albedo_diffuse + sky_diffuse + mirror_reflection + attenuation;
            this->albedo_diffuse    = albedo_diffuse / sum;
            this->sky_diffuse       = sky_diffuse / sum;
            this->mirror_reflection = mirror_reflection / sum;
            this->attenuation       = attenuation / sum;
        }

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
        if (ray.direction * (ret.hit_point - ray.origin) < 0) {
            ret.hit = false;
        }
        ret.hit_sphere = (void*)this;
    }
    return ret;
}

#endif