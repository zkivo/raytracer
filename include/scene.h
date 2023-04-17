#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include "camera.h"
#include "ppm.h"
#include "sphere.h"

using std::vector;

class Scene {

    public:
        const int MAX_DEPTH = 5;
        const int SAMPLE_PER_RAY = 2;
        Camera         camera;
        PPM            ppm;
        vector<Sphere> list_sphere;

        Scene(Camera camera, PPM ppm) :
                camera(camera) ,
                ppm(ppm) {
            list_sphere.push_back(Sphere(float3(0,0,3),
                                  0.99f,
                                  float3(100,0,0),
                                  0, // attenuation
                                  1, // albedo difuse
                                  0, // sky diffuse
                                  0)); //mirror reflection
            list_sphere.push_back(Sphere(float3(2,0,4),
                                  1.0f,
                                  float3(0,0,0),
                                  0, // attenuation
                                  0, // albedo difuse
                                  1, // sky diffuse
                                  0)); //mirror reflection
            list_sphere.push_back(Sphere(float3(-2,0,4),
                                  1.0f,
                                  float3(0,0,200),
                                  0, // attenuation
                                  1, // albedo difuse
                                  1, // sky diffuse
                                  0)); //mirror reflection
        }

        void   render();
        float3 getColor(Ray&, Sphere*, int);


};

#endif