#include "Graphics/render.h"
#include "Graphics/ray.h"
#include "Graphics/image.h"
#include <math.h>
Renderer::Renderer(const Image image)
        :
        image(image)
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
Color ray_color(const ray& r)
{
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);

    //"linear interpolation or lerp"
    // t = 1 -> all blue : t = 0 -> all white. Everything in between is a linear blend
    //lerp in form: Value(t) = (1 - t) * start_color + t * end_color
    return (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}

void Renderer::PixelShader(const uint32_t x, const uint32_t y)
{
    auto u = (double) x / (image.GetWidth() - 1);
    auto v = (double) y / (image.GetHeight() - 1);
    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
    ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    coord c(x, y);
    image.test();
    //image.SetColor(x, y, ray_color(r));
    //std::cout << image.GetHeight() << std::endl;
}
void Renderer::PixelShader(const coord c)
{

}
