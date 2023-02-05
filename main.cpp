#include <iostream>
#include "Graphics/vec3.h"
#include "Graphics/ray.h"
#include "Graphics/image.h"
#include "Graphics/render.h"
#include "Graphics/camera.h"
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
    Image image(aspect_ratio, image_width, image_height);

    //camera 
    Camera camera;
    camera.aspect_ratio = aspect_ratio;
    camera.viewport_height = 2.0;
    camera.viewport_width = aspect_ratio * camera.viewport_height;
    camera.focal_length = 1.0;

    camera.origin = point3(0, 0, 0);
    camera.horizontal = vec3(camera.viewport_width, 0, 0);
    camera.vertical = vec3(0, camera.viewport_height, 0);
    camera.lower_left_corner = camera.origin - camera.horizontal / 2 - camera.vertical / 2 - vec3(0, 0, camera.focal_length);

    //circle
    //Circle circle(image_width / 2, image_height / 2, 64);

    // Render
    Renderer r(image, camera);
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int y = image_height-1; y >= 0; --y) 
    {
        std::cerr << "\rScanlines remaining: " << y << ' ' << std::flush;
        for(int x = 0; x < image_width; ++x) 
        {
            r.PixelShader(x, y);
        }
    }
    r.render();
    image.FreeImage();
    return 0;

}

