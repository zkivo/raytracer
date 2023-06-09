#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "float3.h"
#include "ray.h"
#include "world.h"

// fixed camera pointing in the z direction
// without rotation
class Camera {

    public:
        float3 direction;
        float3 eye_position;
        float  focal_length;  //eye->viewport distance
        int    vp_width_res;  //viewport resolution 
        int    vp_height_res;
        float  vp_aspect_ratio; // width / height
        float  vp_width;      //viewport width
        float  vp_height;
        World  world;

        Camera(const float3& eye_position,
                float focal_length,
                float vp_height,
                float vp_height_res,
                float vp_aspect_ratio,
                World world) :
                direction(0,0,1),
                eye_position(eye_position),
                focal_length(focal_length),
                vp_height(vp_height),
                vp_height_res(vp_height_res),
                vp_aspect_ratio(vp_aspect_ratio),
                world(world) {
            vp_width = vp_height * vp_aspect_ratio;
            vp_width_res = (int)(vp_height_res * vp_aspect_ratio);
        }

        Ray get_ray(int x, int y); //0,0 top left

};

inline Ray Camera::get_ray(int x, int y) {
    float3 dir; //direction of result ray
    if (x >= vp_width_res ||
        x < 0 ||
        y >= vp_height_res ||
        y < 0) {
        throw 20;
    }
    dir = eye_position + direction * focal_length +
          world.x * vp_width / 2 +
          world.y * vp_height / 2 -
          world.x * (x + 1) / vp_width_res * vp_width -
          world.y * (y + 1) / vp_height_res * vp_height;
    dir.normalize();
    return Ray(eye_position, dir);
}

#endif