#include <iostream>
#include "Graphics/Color.h"
#include "Graphics/vec3.h"
#include "Graphics/ray.h"
#include "Graphics/image.h"
#include "Graphics/render.h"

/*
Color ray_color(const ray& r)
{
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);

    //"linear interpolation or lerp"
    // t = 1 -> all blue : t = 0 -> all white. Everything in between is a linear blend
    //lerp in form: Value(t) = (1 - t) * start_color + t * end_color
    return (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}
*/
struct Circle 
{
public:
    double cx, cy, r;
public: 
    Circle() = default;
    Circle(double x, double y, double r)
        :
        cx(x), cy(y), r(r)
    {}

    bool hits_circle(double x, double y) const 
    {
        return ( (x-cx)*(x-cx) + (y-cy)*(y-cy)) - r*r < 100 &&
                  ((x-cx)*(x-cx) + (y-cy)*(y-cy)) - r*r > -100    ;
    }
};

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 16.0;
    const int image_width = 500;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    Image image(image_width, image_height);

    //camera 
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

    //circle
    Circle circle(image_width / 2, image_height / 2, 64);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int y = image_height-1; y >= 0; --y) 
    {
        std::cerr << "\rScanlines remaining: " << y << ' ' << std::flush;
        for(int x = 0; x < image_width; ++x) 
        {
            coord c(x, y);

        }
    }
    Renderer r(image);
    r.render();
    image.FreeImage();
    return 0;

}

