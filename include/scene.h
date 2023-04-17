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
            list_sphere.push_back(Sphere(float3(0,0,4),
                                  1,
                                  float3(0,0,0),
                                  0.05, // attenuation
                                  0, // albedo difuse
                                  0, // sky diffuse
                                  1)); //mirror reflection
            list_sphere.push_back(Sphere(float3(2,0,3),
                                  1.0f,
                                  float3(100,50,50),
                                  0.2, // attenuation
                                  0.3, // albedo difuse
                                  0.3, // sky diffuse
                                  0.15)); //mirror reflection
            list_sphere.push_back(Sphere(float3(-2,0,3),
                                  1.0f,
                                  float3(50,100,50),
                                  0.2, // attenuation
                                  0.3, // albedo difuse
                                  0.3, // sky diffuse
                                  0.15)); //mirror reflection
        }

        void   render();
        float3 getColor(Ray&, Sphere*, int);


};

#endif