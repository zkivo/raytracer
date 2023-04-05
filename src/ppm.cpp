// portable pixmap format
// 255 maximum value for each color 

#include "ppm.h"

ppm::ppm(int width, int height) : width(width), 
        height(height) {
    map = new unsigned char[width * height * 3];
    index_map = 0;
}

// bool ppm::add(unsigned char value) {
//     if (index_map >= width * height * 3) {
//         return false;
//     }
//     map[index_map++] = value;
//     return true;
// }

bool ppm::add_pixel(unsigned char r, 
        unsigned char g, unsigned char b) {
    if (index_map >= width * height * 3) {
        return false;
    }
    map[index_map++] = r;
    map[index_map++] = g;
    map[index_map++] = b;
    return true;
}

bool ppm::write_file(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;
    for (int i = 0; i < index_map; i++) {
        if (i % 3 == 0 && i != 0) {
            file << std::endl;
        }
        file << (int)map[i] << " ";
    }
    file.close();
    return true;
}