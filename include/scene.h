#ifndef _SCENE_H_
#define _SCENE_H_

#include "camera.h"
#include "ppm.h"

class Scene {

    private:
        Camera camera;
        PPM    ppm;
    
    public:
        Scene(Camera camera) : 
            camera(camera) ,
            ppm(PPM(camera.vp_width, camera.vp_height)){}


};

#endif