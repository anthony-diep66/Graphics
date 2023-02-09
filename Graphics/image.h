#ifndef IMAGE_H 
#define IMAGE_H
#include <string.h>
#include "vec3.h"


struct Image 
{
public:
    uint32_t IMAGE_WIDTH;
    uint32_t IMAGE_HEIGHT;
    double aspect_ratio;
    Color **image_data;
public:

    Image(const double ar, const uint32_t width, const uint32_t height);
    void SetColor(const coord& xy, const Color& c);
    void SetColor(const uint32_t x, const uint32_t y, const Color& c);
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    uint8_t* GetRGB(coord xy);
    uint8_t* GetRGB(const uint32_t& x, const uint32_t& y);
    void FreeImage();
};

#endif