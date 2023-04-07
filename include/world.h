#ifndef _WORLD_H_
#define _WORLD_H_

#include "float3.h"

class world {
    public: 
        float3 x;
        float3 y;
        float3 z;
        world() : x(1,0,0),
                  y(0,1,0),
                  z(0,0,1) {} 
};

#endif