#ifndef RENDER_H
#define RENDER_H

#include "vec3.h"
#include "image.h"
#include <iostream>

struct Renderer
{
private:
    Image image;
public: 
    Renderer(const Image image);
    void render();
    void PixelShader(const uint32_t x, const uint32_t y);
    void PixelShader(const coord c);
    void test();
};
#endif