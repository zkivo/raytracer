#include <cmath>
#include "float3.h"

float3::float3() {
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}

float3::float3(const float3& e) {
    v[0] = e.v[0];
    v[1] = e.v[1];
    v[2] = e.v[2];
}

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

float3 float3::get_normalize() {
    float length = this->lenght();
    return float3(this->v[0] / length,
                  this->v[1] / length,
                  this->v[2] / length);
}

float3 float3::unit_vector() {
    return *this / this->lenght();
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

float3& float3::operator=(const float3& e) {
    this->v[0] = e.v[0];
    this->v[1] = e.v[1];
    this->v[2] = e.v[2];    
    return *this;
}

float3 float3::operator+(const float3& e) {
    float3 res;
    res.v[0] = this->v[0] + e.v[0];
    res.v[1] = this->v[1] + e.v[1];
    res.v[2] = this->v[2] + e.v[2];
    return res;
}

float3 float3::operator-(const float3& e) {
    float3 res;
    res.v[0] = this->v[0] - e.v[0];
    res.v[1] = this->v[1] - e.v[1];
    res.v[2] = this->v[2] - e.v[2];    
    return res;
}

float float3::operator*(const float3& e) {
    return this->dot(e);
}

float3 float3::operator*(const float e) {
    float3 res;
    res.v[0] = this->v[0] * e;
    res.v[1] = this->v[1] * e;
    res.v[2] = this->v[2] * e;    
    return res;
}

float3 float3::operator/(const float e) {
    float3 res;
    res.v[0] = this->v[0] / e;
    res.v[1] = this->v[1] / e;
    res.v[2] = this->v[2] / e;    
    return res;
}


bool float3::operator==(const float3& e) {
    return (this->v[0] == e.v[0]) &&
           (this->v[1] == e.v[1]) && 
           (this->v[2] == e.v[2]);
}

float3& float3::operator+=(const float3& e) {
    this->v[0] += e.v[0];
    this->v[1] += e.v[1];
    this->v[2] += e.v[2];
    return *this;
}

float3& float3::operator*=(const float e) {
    this->v[0] *= e;
    this->v[1] *= e;
    this->v[2] *= e;
    return *this;
}

float3& float3::operator-=(const float3& e) {
    this->v[0] -= e.v[0];
    this->v[1] -= e.v[1];
    this->v[2] -= e.v[2];
    return *this;
}

float3& float3::operator++() {
    this->v[0]++;
    this->v[1]++;
    this->v[2]++;
    return *this;
}

float3& float3::operator--() {
    this->v[0]--;
    this->v[1]--;
    this->v[2]--;
    return *this;
}
