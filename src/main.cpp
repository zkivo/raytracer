#include <iostream>
#include "world.h"
#include "float3.h"
#include "ppm.h"
#include "scene.h"

int main() {
    
    const short height_res   = 600;
    const float focal_length = 1;
    const float viewport_height = 1;
    const float aspect_ratio = 16.0f / 9.0f; 

    World world(float3(1.0f, 0.0f, 0.0f),
                float3(0.0f, 1.0f, 0.0f),
                float3(0.0f, 0.0f, 1.0f));

    Camera camera(float3(0.0f,0.0f,0.0f),
                  focal_length,
                  viewport_height,
                  height_res,
                  aspect_ratio,
                  world);

    PPM ppm(camera.vp_width_res, height_res);

    Scene scene(camera, ppm);

    scene.render();

    return 0;
}