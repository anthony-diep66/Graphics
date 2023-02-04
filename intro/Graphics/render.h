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

    void WritePixel(const Color pixel_color)
    {
        /*
        out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
        */

        uint32_t width = image.GetWidth();
        uint32_t height = image.GetHeight();
        for(auto i = 0; i < height; i++)
        {
            for(auto j = 0; j < width; j++)
            {
                
            }
        }
    }
};

#endif