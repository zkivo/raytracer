#include "float3.h"
#include "ray.h"

ray::ray(const float3& origin, const float3& direction) {
    this->origin = float3(origin);
    this->direction = float3(direction);
}

float3 ray::get_origin() {
    return this->origin;
}

float3 ray::get_direction() {
    return this->direction;
}

float3 ray::at(float t) {
    return origin + direction * t;
}