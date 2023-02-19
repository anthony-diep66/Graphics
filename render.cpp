#include "Graphics/render.h"
#include "Graphics/ray.h"
#include "Graphics/image.h"
#include "Graphics/vec3.h"
#include <math.h>
Renderer::Renderer(const Image image, const Camera camera)
        :
        image(image), camera(camera)
    {}

void Renderer::render()
{
    uint8_t* rgb_val;
    for(auto i = image.GetHeight() - 1; i-- > 0; )
    {
        for(auto j = 0; j < image.GetWidth(); ++j)
        {
            coord c(j, i);
            rgb_val = image.GetRGB(i, j);
            std::cout << (unsigned)rgb_val[0] << " "
                        << (unsigned)rgb_val[1] << " "
                        << (unsigned)rgb_val[2] << "\n";
        }
    }
}


void Renderer::PixelShader(Scene scene, const uint32_t x, const uint32_t y)
{
    auto u = (double) x / (image.GetWidth() - 1);
    auto v = (double) y / (image.GetHeight() - 1);
    ray r(camera.origin, camera.lower_left_corner + u*camera.horizontal + v*camera.vertical - camera.origin); 
    image.SetColor(y, x, r.ray_color());
}
