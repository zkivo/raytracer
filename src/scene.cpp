#include <cmath>
#include "scene.h"
#include "float3.h"
#include "ray.h"

float3 Scene::getColor(Ray& ray, int depth) {
    if (depth = 0) {
        return float3(0,0,0); // black
    }
    HasHit nearest_hit;
    nearest_hit.hit = false;
    bool first = true;
    for (Sphere sphere : list_sphere) {
        HasHit has_hit = sphere.hasHit(ray);
        if (has_hit.hit == false) continue;
        if (first) {
            nearest_hit = has_hit;
            first = false;
            continue;
        }
        if (has_hit.length_ray < nearest_hit.length_ray) {
            nearest_hit = has_hit;
        }
    }
    if (nearest_hit.hit == false) {
        float y = 0.5*(ray.direction.v[1] + 1.0);
        return float3(255,255,255)*(1-y) + float3(100,200,255)*y;
    } else {
        // calculate random bouncing ray
        // and call recursively this function with 50% absorption
        return float3(0,0,0);
    }
}

void Scene::render() {
    Ray ray;
    float3 color;
    for (int i = 0; i < camera.vp_height_res; i++) {
        for (int j = 0; j < camera.vp_width_res; j++) {
            ray = camera.get_ray(j, i);
            color = getColor(ray, MAX_DEPTH);
            ppm.add_pixel(color.v[0], color.v[1], color.v[2]);
        }
    }
    ppm.write_file("output.ppm");
}