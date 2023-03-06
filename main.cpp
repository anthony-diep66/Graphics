#include <iostream>
#include "utils/utils.cpp"
#include "Graphics/image.h"
#include "Graphics/render.h"
#include "Graphics/scene.h"
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

    //construct a scene
    Scene world;
    world.add(make_shared<Sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(point3(0, -100.5, -1), 100));

    // Render
    Renderer r(image, camera);
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int y = image_height-1; y >= 0; --y) 
    {
        std::cerr << "\rScanlines remaining: " << y << ' ' << std::flush;
        for(int x = 0; x < image_width; ++x) 
        {
            r.PixelShader(world, x, y);
        }
    }
    r.render();
    image.FreeImage();
    return 0;

}

