#ifndef _SCENE_H_
#define _SCENE_H_

#include "camera.h"
#include "ppm.h"

class Scene {

    private:
        Camera camera;
        PPM    ppm;
    
    public:
        Scene(Camera camera, PPM ppm) : 
            camera(camera) ,
            ppm(ppm){}
        
        void render();


};

#endif