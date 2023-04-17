#ifndef _FLOAT3_H_
#define _FLOAT3_H_

#include <cmath>

class float3 {

    public:
        float v[3];

        float3();
        float3(const float3& e);
        float3(float e1, float e2, float e3);

        float  lenght();
        void   normalize();
        float3 get_normalize();
        float  dot(const float3& e);
        float3 cross(const float3& e);
        float3 unit_vector();

        float3& operator=(const float3& e);
        float3  operator+(const float3& e);
        float3  operator-(const float3& e);
        float   operator*(const float3& e);
        float3  operator*(const float e);
        float3  operator/(const float e);
        bool    operator==(const float3& e);
        float3& operator+=(const float3& e);
        float3& operator*=(const float e);
        float3& operator-=(const float3& e);
        float3& operator++();
        float3& operator--();
};

inline float3::float3() {
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}

inline float3::float3(const float3& e) {
    v[0] = e.v[0];
    v[1] = e.v[1];
    v[2] = e.v[2];
}

inline float3::float3(float e1, float e2, float e3) {
    v[0] = e1;
    v[1] = e2;
    v[2] = e3;
}

inline float float3::lenght() {
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

inline void float3::normalize() {
    float length = this->lenght();
    v[0] /= length;
    v[1] /= length;
    v[2] /= length;
}

inline float3 float3::get_normalize() {
    float length = this->lenght();
    return float3(this->v[0] / length,
                  this->v[1] / length,
                  this->v[2] / length);
}

inline float3 float3::unit_vector() {
    return *this / this->lenght();
}

inline float float3::dot(const float3& e) {
    return (this->v[0] * e.v[0]) + 
           (this->v[1] * e.v[1]) + 
           (this->v[2] * e.v[2]);
}

inline float3 float3::cross(const float3& e) {
    return float3(
        this->v[1] * e.v[2] - this->v[2] * e.v[1],
        this->v[2] * e.v[0] - this->v[0] * e.v[2],
        this->v[0] * e.v[1] - this->v[1] * e.v[0]
    );
}

inline float3& float3::operator=(const float3& e) {
    this->v[0] = e.v[0];
    this->v[1] = e.v[1];
    this->v[2] = e.v[2];    
    return *this;
}

inline float3 float3::operator+(const float3& e) {
    float3 res;
    res.v[0] = this->v[0] + e.v[0];
    res.v[1] = this->v[1] + e.v[1];
    res.v[2] = this->v[2] + e.v[2];
    return res;
}

inline float3 float3::operator-(const float3& e) {
    float3 res;
    res.v[0] = this->v[0] - e.v[0];
    res.v[1] = this->v[1] - e.v[1];
    res.v[2] = this->v[2] - e.v[2];    
    return res;
}

inline float float3::operator*(const float3& e) {
    return this->dot(e);
}

inline float3 float3::operator*(const float e) {
    float3 res;
    res.v[0] = this->v[0] * e;
    res.v[1] = this->v[1] * e;
    res.v[2] = this->v[2] * e;    
    return res;
}

inline float3 float3::operator/(const float e) {
    float3 res;
    res.v[0] = this->v[0] / e;
    res.v[1] = this->v[1] / e;
    res.v[2] = this->v[2] / e;    
    return res;
}


inline bool float3::operator==(const float3& e) {
    return (this->v[0] == e.v[0]) &&
           (this->v[1] == e.v[1]) && 
           (this->v[2] == e.v[2]);
}

inline float3& float3::operator+=(const float3& e) {
    this->v[0] += e.v[0];
    this->v[1] += e.v[1];
    this->v[2] += e.v[2];
    return *this;
}

inline float3& float3::operator*=(const float e) {
    this->v[0] *= e;
    this->v[1] *= e;
    this->v[2] *= e;
    return *this;
}

inline float3& float3::operator-=(const float3& e) {
    this->v[0] -= e.v[0];
    this->v[1] -= e.v[1];
    this->v[2] -= e.v[2];
    return *this;
}

inline float3& float3::operator++() {
    this->v[0]++;
    this->v[1]++;
    this->v[2]++;
    return *this;
}

inline float3& float3::operator--() {
    this->v[0]--;
    this->v[1]--;
    this->v[2]--;
    return *this;
}

#endif