#include <string.h>
#include "Graphics/image.h"

enum RGB { red, green, blue };

Image::Image(const double ar, const uint32_t width, const uint32_t height)
    :
    aspect_ratio(ar), IMAGE_WIDTH(width), IMAGE_HEIGHT(height)
{
    image_data = new Color*[IMAGE_HEIGHT];
    for(int i = 0; i < IMAGE_HEIGHT; i++)
    {
        image_data[i] = new Color[IMAGE_WIDTH];
    }
}

void Image::SetColor(const coord& xy, const Color& c)
{
    uint32_t x = (uint32_t)xy.x();
    uint32_t y = (uint32_t)xy.y();
    image_data[y][x][0] = c.x();
    image_data[y][x][1] = c.y();
    image_data[y][x][2] = c.z();
}

void Image::test()
{

}

void Image::SetColor(const uint32_t x, const uint32_t y, const Color& c)
{
    image_data[y][x][0] = c.x();
    image_data[y][x][1] = c.y();
    image_data[y][x][2] = c.z();
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

uint8_t* Image::GetRGB(const uint32_t& x, const uint32_t& y) 
{
    uint8_t ans[3];
    ans[0] = static_cast<int>(255.999 *image_data[y][x][red]);
    ans[1] = static_cast<int>(255.999 *image_data[y][x][green]);
    ans[2] = static_cast<int>(255.999 *image_data[y][x][blue]);
    uint8_t *p = ans;
    return p;
}