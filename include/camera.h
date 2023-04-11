#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "float3.h"
#include "ray.h"

class camera {

    private:
        float3 eye_position;
        float3 direction;
        float  focal_length;  //eye->viewport distance
        float  vp_width;      //viewport width
        float  vp_width_res;  //viewport resolution 
        float  vp_height_res;
        world  world;

    public:
        camera(const float3& eye_position,
               const float3& direction,
               float focal_length,
               float vp_width,
               float vp_height_res,
               float vp_width_res,
               world world) :
               eye_position(eye_position),
               direction(direction),
               focal_length(focal_length),
               vp_width(vp_width),
               vp_height_res(vp_height_res),
               vp_width_res(vp_width_res),
               world(world) {}

        ray get_ray(int x, int y); //0,0 top left

};

#endif