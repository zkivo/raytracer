#include <iostream>
#include "world.h"
#include "ppm.h"

int main() {
    
    const short width  = 800;
    const short height = 600;

    World world(float3(1.0f, 0.0f, 0.0f),
                float3(0.0f, 1.0f, 0.0f),
                float3(0.0f, 0.0f, 1.0f));

    PPM map(width, height);

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