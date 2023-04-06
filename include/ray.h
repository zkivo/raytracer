#ifndef _RAY_H_
#define _RAY_H_

#include "float3.h"

class ray {

    private:
        float3 origin;
        float3 direction;
    
    public:
        ray() : origin(), direction() {}
        ray(const float3& origin, const float3& direction);

        float3 get_origin();
        float3 get_direction();

        float3 at(float t);  

};

#endif