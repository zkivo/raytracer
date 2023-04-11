#include "ray.h"
#include "float3.h"
#include "camera.h"

ray camera::get_ray(int x, int y) {
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
          world.y * (y + 1) / vp_heigth_res * vp_height;
    dir.normalize();
    return ray(eye_position, dir);
}