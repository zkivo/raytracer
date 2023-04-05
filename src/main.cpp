// #include "toojpeg.h"
// #include <fstream>
#include <iostream>
#include "ppm.h"
// std::ofstream render_file("output.jpg", std::ios_base::out | std::ios_base::binary);

// void output_f(unsigned char byte) {
//     render_file << byte;
// } 

int main() {
    
    const short width  = 800;
    const short height = 600;
    // const int byte_per_pixel = 3;

    // auto image = new unsigned char[width * height * byte_per_pixel];

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
    // const bool is_RGB = true;
    // const unsigned char quality = 90;
    // const bool downsample = false;
    // TooJpeg::writeJpeg(output_f, image, width, height, is_RGB, quality, downsample, NULL);

    return 0;
}