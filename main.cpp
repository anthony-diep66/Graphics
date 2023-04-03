#include <iostream>
#include "utils/utils.cpp"
#include "Graphics/image.h"
#include "Graphics/render.h"
#include "Graphics/scene.h"
int main() {
    // Image
    const auto aspect_ratio = 16.0 / 16.0;
    const int image_width = 600;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    Image image(aspect_ratio, image_width, image_height);

    //camera 
    Camera camera;

    //construct a scene
    Scene world;
    world.add(make_shared<Sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(point3(0, -110.5, -1), 100));

    // Render
    Renderer r(image, camera);
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int y = image_height-1; y >= 0; --y) 
    {
        std::cerr << "\rScanlines remaining: " << y << ' ' << std::flush;
        for(int x = 0; x < image_width; ++x) 
        {
            r.PixelShader(world, x, y, camera);
        }
    }
    r.render();
    image.FreeImage();
    return 0;

}

