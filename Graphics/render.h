#ifndef RENDER_H
#define REDNER_H

#include "vec3.h"
#include "image.h"
#include <iostream>

struct Renderer
{
private:
    Image image;
public: 
    Renderer(const Image image)
        :
        image(image)
    {}

    void render()
    {
        uint32_t width = image.GetWidth();
        uint32_t height = image.GetHeight();
        std::cout << "width = " << width << "\theight = " << height << std::endl;
        uint8_t* rgb_val;
        for(auto i = height - 1; i-- > 0; )
        {
            for(auto j = 0; j < width; ++j)
            {
                coord c(j, i);
                rgb_val = image.GetRGB(c);
                std::cout << (unsigned)rgb_val[0] << " "
                          << (unsigned)rgb_val[1] << " "
                          << (unsigned)rgb_val[2] << "\n";
            }
        }
    }
};

#endif