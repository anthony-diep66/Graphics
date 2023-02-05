#ifndef RENDER_H
#define RENDER_H

#include "image.h"
#include <iostream>

struct Renderer
{
private:
    Image image;
public: 
    const double aspect_ratio = 16.0 / 16.0;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;
public: 
    Renderer(const Image image);
    void render();
    void PixelShader(const uint32_t x, const uint32_t y);
    void PixelShader(const coord c);
};
#endif