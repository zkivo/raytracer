// portable pixmap format
// 255 maximum value for each color 
#ifndef _PPM_H_
#define _PPM_H_

#include <iostream>
#include <fstream>
#include <string>

class PPM {
    private:
        int  height;
        int  width;
        int  index_map;
        unsigned char *map;
    public:
        PPM(int width, int height);

        bool add_pixel(unsigned char,
                       unsigned char,
                       unsigned char);

        bool write_file(const std::string &filename);
};

#endif