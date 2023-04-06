#include "float3.h"
#include "ray.h"

ray::ray(const float3& origin, const float3& direction) {
    origin = flaot3(origin);
    direction = float3(direction);
}

float3 ray::origin() {
    return this->origin;
}

float3 ray::direction() {
    return this->direction;
}

flaot3 ray::at(flaot t) {
    return origin + t * direction;
}