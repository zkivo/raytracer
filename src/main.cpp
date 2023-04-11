#include <iostream>
#include "world.h"
#include "ppm.h"

int main() {
    
    const short width  = 800;
    const short height = 600;

    world world(float3(1,0,0),
                float3(0,1,0)
                float3(0,0,1));

    ppm map(width, height);

    // std::cout << "asd" << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map.add_pixel((int)(255 * j / width), 
                          (int)(255 * i / height),
                          127);
        }
    }

    map.write_file("output.ppm");

    return 0;
}