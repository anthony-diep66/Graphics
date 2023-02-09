#ifndef RENDER_H
#define RENDER_H

#include "image.h"
#include "camera.h"
#include <iostream>

struct Renderer
{
private:
    Image image;
    Camera camera;
public: 
    Renderer(const Image image, const Camera camera);
    void render();
    void PixelShader(const uint32_t x, const uint32_t y);
};
#endif