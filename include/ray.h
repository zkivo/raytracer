#ifndef _RAY_H_
#define _RAY_H_

#include "float3.h"

class Ray {

    public:
        float3 origin;
        float3 direction;

        Ray() : origin(), direction() {}
        Ray(const float3& origin, const float3& direction);

        float3 get_origin();
        float3 get_direction();

        float3 at(float t);  

};

inline Ray::Ray(const float3& origin, const float3& direction) {
    this->origin = float3(origin);
    this->direction = float3(direction);
}

inline float3 Ray::get_origin() {
    return this->origin;
}

inline float3 Ray::get_direction() {
    return this->direction;
}

inline float3 Ray::at(float t) {
    return origin + direction * t;
}

#endif