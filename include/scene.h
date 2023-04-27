#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>
#include <cstdlib>
#include <ctime>
#include "camera.h"
#include "ppm.h"
#include "sphere.h"

using std::vector;

class Scene {

    public:
        const int MAX_DEPTH = 10;
        const int SAMPLE_PER_RAY = 25;
        Camera         camera;
        PPM            ppm;
        vector<Sphere> list_sphere;

        // #731AE5 purple  115 26  229 - 0.45 0.1  0.9
        // #E5731A orange  229 115 26  - 0.9  0.45 0.1
        // #1AE573 green   26  229 115 - 0.1  0.9  0.45

        // #5923DC  89  35  220
        // #A6DC23  166 200 35

        Scene(Camera camera, PPM ppm) :
                camera(camera) ,
                ppm(ppm) {
            list_sphere.push_back(Sphere(float3(0,-101.1,0),
                                  float3(0.95,0,0),
                                  100,
                                  false));
            list_sphere.push_back(Sphere(float3(0,0,4.45),
                                  float3(0.9,0.9,0.9),
                                  1,
                                  true));
            list_sphere.push_back(Sphere(float3(2,0,4),
                                  float3(0.2,0.67,0.8),
                                  1,
                                  false));
            list_sphere.push_back(Sphere(float3(-2,0,4),
                                  float3(0.45,0.1,0.9),
                                  1,
                                  false));
            list_sphere.push_back(Sphere(float3(3,0,2.5),
                                  float3(0.9,0.45,0.1),
                                  1,
                                  false));
            list_sphere.push_back(Sphere(float3(-3,0,2.5),
                                  float3(0.1,0.9,0.45),
                                  1,
                                  false));
            // std::srand(std::time(nullptr));
            // int n_sphere = (std::rand() % 200) + 100;
            // float3 center(0,0,10);
            // float3 colore;
            // float  x_wide = 12;
            // float  y_wide = 12;
            // float  z_wide = 8;
            // float  radius = 0.3;
            // for (int i = 0; i < n_sphere; i++) {
            //     float x = range() * x_wide;
            //     float y = range() * y_wide;
            //     float z = range() * z_wide;
            //     bool mirror = false;
            //     center.v[0] = x - (x_wide/2.0f);
            //     center.v[1] = y - (y_wide/2.0f);
            //     center.v[2] = z - (z_wide/2.0f) + 10;
            //     switch(std::rand() % 3) {
            //         case 0:
            //             colore.v[0] = 0.45;
            //             colore.v[1] = 0.1;
            //             colore.v[2] = 0.9;                        
            //         break;
            //         case 1:
            //             colore.v[0] = 0.9;
            //             colore.v[1] = 0.45;
            //             colore.v[2] = 0.1;  
            //         break;
            //         case 2:
            //             colore.v[0] = 0.1;
            //             colore.v[1] = 0.9;
            //             colore.v[2] = 0.45;
            //         break;                    
            //     }
            //     if (std::rand() % 10 <= 1) mirror = true;
            //     if (mirror) {
            //         colore.v[0] = 1;
            //         colore.v[1] = 1;
            //         colore.v[2] = 1;
            //     }
            //     list_sphere.push_back(Sphere(center,
            //                                  colore,
            //                                  radius,
            //                                  mirror));
            // }
        }
        float range() {
            return (float)std::rand() / (float)RAND_MAX;
        }

        void   render();
        float3 getColor(Ray&, Sphere*, int);
};

#endif