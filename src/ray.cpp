#include "float3.h"
#include "ray.h"

Ray::Ray(const float3& origin, const float3& direction) {
    this->origin = float3(origin);
    this->direction = float3(direction);
}

float3 Ray::get_origin() {
    return this->origin;
}

float3 Ray::get_direction() {
    return this->direction;
}

float3 Ray::at(float t) {
    return origin + direction * t;
}