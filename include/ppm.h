// portable pixmap format
// 255 maximum value for each color 
#ifndef _PPM_H_
#define _PPM_H_

#include <iostream>
#include <fstream>
#include <string>

class ppm {
    private:
        int  height;
        int  width;
        int  index_map;
        unsigned char *map;
    public:
        ppm(int height, int width);

        bool add(unsigned char value);

        bool write_file(const std::string &filename);
};

#endif