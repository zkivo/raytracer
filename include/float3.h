#ifndef _FLOAT3_H_
#define _FLOAT3_H_

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



#endif