#include <cmath>
#include "float3.h"

float3::float3(float e1, float e2, float e3) {
    v[0] = e1;
    v[1] = e2;
    v[2] = e3;
}

float float3::lenght() {
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

void float3::normalize() {
    float length = this->lenght();
    v[0] /= length;
    v[1] /= length;
    v[2] /= length;
}

float float3::dot(const float3& e) {
    return (this->v[0] * e.v[0]) + 
           (this->v[1] * e.v[1]) + 
           (this->v[2] * e.v[2]);
}

float3 float3::cross(const float3& e) {
    return float3(
        this->v[1] * e.v[2] - this->v[2] * e.v[1],
        this->v[2] * e.v[0] - this->v[0] * e.v[2],
        this->v[0] * e.v[1] - this->v[1] * e.v[0]
    );
}