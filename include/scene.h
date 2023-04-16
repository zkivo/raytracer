#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include "camera.h"
#include "ppm.h"
#include "sphere.h"

using std::vector;

class Scene {

    public:
        const int MAX_DEPTH = 10;
        const int SAMPLE_PER_RAY = 20;
        Camera         camera;
        PPM            ppm;
        vector<Sphere> list_sphere;

        Scene(Camera camera, PPM ppm) :
                camera(camera) ,
                ppm(ppm) {
            list_sphere.push_back(Sphere(float3(0,0,3),  1.0f));
            list_sphere.push_back(Sphere(float3(2,0,4),  1.0f));
            list_sphere.push_back(Sphere(float3(-2,0,4), 1.0f));
        }

        void   render();
        float3 getColor(Ray&, Sphere*, int);


};

#endif