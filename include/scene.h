#ifndef _SCENE_H_
#define _SCENE_H_

#include "camera.h"
#include "ppm.h"

class scene {

    private:
        camera camera;
        ppm    ppm;
    
    public:
        scene(camera camera) : 
            camera(camera) ,
            ppm(ppm()){}


};

#endif