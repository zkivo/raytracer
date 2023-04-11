#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "float3.h"
#include "ray.h"


// fixed camera pointing in the z direction
// without rotation
class camera {

    private:
        float3 direction;
        float3 eye_position;
        float  focal_length;  //eye->viewport distance
        float  vp_width;      //viewport width
        float  vp_height;
        int    vp_width_res;  //viewport resolution 
        int    vp_height_res;
        float  vp_aspect_ratio; // width / height

    public:
        camera(const float3& eye_position,
                float focal_length,
                float vp_width,
                float vp_height_res,
                float vp_aspect_ratio) :
                direction(0,0,1),
                eye_position(eye_position),
                focal_length(focal_length),
                vp_width(vp_width),
                vp_height_res(vp_height_res),
                vp_aspect_ratio(vp_aspect_ratio) {
            vp_height = vp_width / vp_aspect_ratio;
            vp_height_res = (int)(vp_width_res / vp_aspect_ratio);
        }

        ray get_ray(int x, int y); //0,0 top left

};

#endif