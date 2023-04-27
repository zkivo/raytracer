// portable pixmap format
// 255 maximum value for each color 

#include "ppm.h"

PPM::PPM(int width, int height) : width(width), 
        height(height) {
    map = new unsigned char[width * height * 3];
}

void PPM::set_pixel(int x, int y,
        unsigned char r, unsigned char g, unsigned char b) {
    map[y*width*3 + x*3 + 0] = r;
    map[y*width*3 + x*3 + 1] = g;
    map[y*width*3 + x*3 + 2] = b;
}

bool PPM::write_file(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;
    for (int i = 0; i < 3*width*height; i++) {
        if (i % 3 == 0 && i != 0) {
            file << std::endl;
        }
        file << (int)map[i] << " ";
    }
    file.close();
    return true;
}