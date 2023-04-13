#include <cmath>
#include "scene.h"
#include "float3.h"
#include "ray.h"

void Scene::render() {
    Ray ray;
    for (int i = 0; i < camera.vp_height_res; i++) {
        for (int j = 0; j < camera.vp_width_res; j++) {
            ray = camera.get_ray(j, i);
            // suppose we have a sphere centered in (0,0,3)
            float3 A = ray.origin;
            float3 B = ray.direction;
            float3 C(0,0,3);
            float  r = 1;
            float  a = B * B;
            float  b = 2 * (B * (A - C));
            float  c = ((A - C)*(A - C)) - r * r; 
            float  delta = b * b - 4 * a * c;
            float  t1 = (-b - std::sqrt(delta)) / 2*a; 
            float  t2 = (-b + std::sqrt(delta)) / 2*a; 
            if (delta >= 0) {
                float3 normal = ray.at(t1) - C;
                normal.normalize();
                float3 color(normal.v[0] + 1,
                             normal.v[1] + 1,
                             normal.v[2] + 1);
                color *= 0.5f;
                ppm.add_pixel(color.v[0] * 255,
                              color.v[1] * 255,
                              color.v[2] * 255);
            } else {
                ppm.add_pixel(0,(float)(i/camera.vp_height_res)*127,0);
            }
        }
    }
    ppm.write_file("output.ppm");
}