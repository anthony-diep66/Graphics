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

    //perspective projection 
    //ray r(camera.origin, camera.lower_left_corner + u*camera.horizontal + v*camera.vertical - camera.origin); 

    //ortho
    ray r(camera.origin + camera.lower_left_corner + u * camera.horizontal + v * camera.vertical, vec3(0, 0, -1));

    Color c;
    //from ray.cpp
    Sphere s(point3(0,0.9,-1), 0.5);
    s.color = Color(1,0,1);

    point3 spherecenter = s.center + vec3(0, 0, -1);
    Sphere ts(spherecenter, s.radius);
    double t = ts.hit(r);

    if( t <= 0 )    //doesn't hit
    {
        t = 1 + (r.dir.y() * 0.5);
        image.SetColor(y, x, (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0));
        return;
    }

    vec3 N = unit_vector(r.at(t) - ts.center);
    N = unit_vector(N + vec3(1,1,1));
    point3 light_source = unit_vector(vec3(-1,-1,-1));
    double d = dot(N, -light_source);
    if( d < 0 )
        d = 0;
    c = 0.5 * (N + point3(1, 1, 1));
    c *= d;
        

    image.SetColor(y, x, c);
}
