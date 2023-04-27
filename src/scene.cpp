#include <cmath>
#include <cstdlib>
#include <ctime>
#include "scene.h"
#include "float3.h"
#include "ray.h"

float3 rand_vector() {
    float x = ((float)std::rand() / (float)RAND_MAX) * 2 - 1;
    float y = ((float)std::rand() / (float)RAND_MAX) * 2 - 1;
    float z = ((float)std::rand() / (float)RAND_MAX) * 2 - 1;
    return float3(x,y,z);
}

float3 Scene::getColor(Ray& ray, Sphere* origin_sphere, int depth) {
    if (depth == 0) {
        return float3(0,0,0);
    }
    HasHit nearest_hit;
    nearest_hit.hit = false;
    bool first = true;
    for (Sphere& sphere : list_sphere) {
        HasHit has_hit = sphere.hasHit(ray);
        if (has_hit.hit == false) continue;
        if (has_hit.hit_sphere == (void*)origin_sphere) continue;
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
        return float3(255,225,255)*(1-y) + float3(130,178,255)*y;
    } else {
        // has hit a sphere
        Sphere* hit_sphere = (Sphere*)nearest_hit.hit_sphere;
        float3 scatter_direction;
        if (hit_sphere->mirror) {
            scatter_direction = ray.direction - nearest_hit.normal*(nearest_hit.normal * ray.direction) *2;
        } else {
            float3 r_vector = rand_vector().get_normalize();
            scatter_direction = nearest_hit.normal + r_vector;
        }     
        scatter_direction.normalize();
        Ray scatter_ray(nearest_hit.hit_point, scatter_direction);
        float3 color = getColor(scatter_ray, hit_sphere, depth - 1);
        color.v[0] *= hit_sphere->albedo.v[0];
        color.v[1] *= hit_sphere->albedo.v[1];
        color.v[2] *= hit_sphere->albedo.v[2];
        color.clearNAN();
        return color;
    }
}

void Scene::render() {
    std::srand(std::time(nullptr));
    #pragma omp parallel for
    for (int i = 0; i < camera.vp_height_res; i++) {
        for (int j = 0; j < camera.vp_width_res; j++) {
            Ray ray;
            float3 color;
            ray = camera.get_ray(j, i);
            color.v[0] = 0;
            color.v[1] = 0;
            color.v[2] = 0;
            for (int s = 1; s <= SAMPLE_PER_RAY; s++) {
                color += getColor(ray, NULL, MAX_DEPTH) / (float)SAMPLE_PER_RAY;
            }
            ppm.set_pixel(j, i, color.v[0], color.v[1], color.v[2]);
        }
    }
    ppm.write_file("output.ppm");
}