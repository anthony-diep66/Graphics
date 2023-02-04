#ifndef IMAGE_H 
#define IMAGE_H
#include <string.h>
#include "vec3.h"
#include "Color.h"

enum RGB { red, green, blue };

struct Image 
{
public:
    uint32_t IMAGE_WIDTH;
    uint32_t IMAGE_HEIGHT;
    Color **image_data;
public:

    Image(const uint32_t width, const uint32_t height)
        :
        IMAGE_WIDTH(width), IMAGE_HEIGHT(height)
    {
        image_data = new Color*[IMAGE_HEIGHT];
        for(int i = 0; i < IMAGE_HEIGHT; i++)
        {
            image_data[i] = new Color[IMAGE_WIDTH];
        }
    }

    void SetColor(const coord& xy, const Color& c);
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    uint8_t* GetRGB(coord xy);
    void FreeImage();

};

void Image::SetColor(const coord& xy, const Color& c)
{
    uint32_t x = (uint32_t)xy.x();
    uint32_t y = (uint32_t)xy.y();
    image_data[y][x][0] = c.r();
    image_data[y][x][1] = c.g();
    image_data[y][x][2] = c.b();
}

void Image::FreeImage() 
{
    for(int i = 0; i < IMAGE_HEIGHT; i++)
    {
        free(image_data[i]);
    }
    free(image_data);
}

uint32_t Image::GetHeight() const
{
    return IMAGE_HEIGHT;
}

uint32_t Image::GetWidth() const 
{
    return IMAGE_WIDTH;
}

uint8_t* Image::GetRGB(coord xy) 
{
    uint8_t ans[3];
    uint32_t x = (uint32_t) xy.x();
    uint32_t y = (uint32_t) xy.y();
    ans[0] = static_cast<int>(255.999 *image_data[y][x][red]);
    ans[1] = static_cast<int>(255.999 *image_data[y][x][green]);
    ans[2] = static_cast<int>(255.999 *image_data[y][x][blue]);
    uint8_t *p = ans;
    return p;
}

#endif