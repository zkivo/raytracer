#ifndef _WORLD_H_
#define _WORLD_H_

#include "float3.h"

class World {

    public:
        float3 x;
        float3 y;
        float3 z;

        World(float3 x, float3 y, float3 z) : x(x), y(y), z(z) {}

};

#endif
