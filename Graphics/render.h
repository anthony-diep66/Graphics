#ifndef RENDER_H
#define RENDER_H

#include "image.h"
#include "camera.h"
#include "scene.h"
#include <iostream>

struct Renderer
{
private:
    Image image;
    Camera camera;
public: 
    Renderer(const Image image, const Camera camera);
    void render();
    void PixelShader(const Scene& scene, const uint32_t x, const uint32_t y, const Camera camera);
};
#endif