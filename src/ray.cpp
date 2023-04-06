#include "ray.h"

ray::ray(float3& origin, float3& direction) {
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