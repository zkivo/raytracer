#ifndef _WORLD_H_
#define _WORLD_H_

#include "float3.h"

class world {

    public:
        float3 x;
        float3 y;
        float3 z;

    float3(float x, float y, float z) : x(x), y(y), z(z) {}

};

#endif
