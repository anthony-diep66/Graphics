#ifndef IMAGE_H 
#define IMAGE_H
#include <string.h>
#include "vec3.h"
#include "Color.h"
struct Image 
{
public:
    uint32_t IMAGE_WIDTH;
    uint32_t IMAGE_HEIGHT;
    uint8_t ***image_data;
public:

    Image(const uint32_t width, const uint32_t height)
        :
        IMAGE_WIDTH(width), IMAGE_HEIGHT(height)
    {
        image_data = new uint8_t**[IMAGE_HEIGHT];
        for(int i = 0; i < IMAGE_HEIGHT; i++)
        {
            image_data[i] = new uint8_t*[IMAGE_WIDTH];
            for(int j = 0; j < IMAGE_WIDTH; j++)
            {
                image_data[i][j] = new uint8_t[3];
                image_data[i][j][0] = image_data[i][j][1] = image_data[i][j][2] = 0;
            }
        }
    }

    void PrintImage() const;
    void SetColor(const coord& xy, const Color& c);
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    double* GetRGB(coord xy) const;
    void FreeImage();

};

void Image::PrintImage() const
{
    for(int i = 0; i < IMAGE_HEIGHT; i++)
    {
        for(int j = 0; j < IMAGE_WIDTH; j++)
        {
            std::cout <<    (unsigned)image_data[i][j][0] << " " <<
                            (unsigned)image_data[i][j][1] << " " <<
                            (unsigned)image_data[i][j][2] << "\n";
        }
        std::cout << std::endl;
    }
}

void Image::SetColor(const coord& xy, const Color& c)
{

}

void Image::FreeImage() 
{
    for(int i = 0; i < IMAGE_HEIGHT; i++)
    {
        for(int j = 0; j < IMAGE_WIDTH; j++)
        {
            free(image_data[i][j]);
        }
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

double* Image::GetRGB(coord xy) const
{
    double res[] = {xy.y(), xy.x(), xy.z()};
    return res;
}

#endif