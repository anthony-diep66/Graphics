#include "Graphics/render.h"
#include "Graphics/image.h"
#include "utils/utils.cpp"
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

void Renderer::PixelShader(const Scene& scene, const uint32_t x, const uint32_t y, const Camera camera)
{
    auto u = (double) x / (image.GetWidth() - 1);
    auto v = (double) y / (image.GetHeight() - 1);


    //perspective projection 
    //ray r({0,0,0}, camera.lower_left_corner + u*camera.horizontal + v*camera.vertical); 
    ray r = camera.get_ray(u, v);
    hit_record record;
    if( scene.hit(r, 0, infinity, record) )
    {
        image.SetColor(y, x, 0.5 * (record.normal + Color(1,1,1)));
    }
    else
    {
        //auto t = 1 + (r.dir.y() * 0.5);
        //image.SetColor(y, x, (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0));

        vec3 unit_direction = unit_vector(r.direction());
        auto t = 0.5*(unit_direction.y() + 1.0);
        image.SetColor(y, x, (1.0-t)*Color(1.0,1.0,1.0)+t*Color(0.5,0.7,1.0));
    }
    /*vec3 direction = vec3(u * camera.viewport_width, v * camera.viewport_height, 0);
    ray r(camera.origin + direction, vec3(0, 0, -1));
    */
    //ortho: when using, move camera or object back
    //ray r(camera.lower_left_corner + u * camera.horizontal + v * camera.vertical - camera.origin, vec3(0, 0, -1));
    /*
    Color c;
    double t = 1e6;
    Sphere closest;
    //Sphere s(point3(0,0,-1), 0.5);
    for(Sphere sphere : scene.Spheres)
    {
        double tt = sphere.hit(r);
        if( tt <= 0 )    //doesn't hit
            continue;
        vec3 N = unit_vector(r.at(tt) - sphere.center);
        N = unit_vector(N + vec3(1,1,1));
        point3 light_source = unit_vector(vec3(-1,-1,-1));
        double d = dot(N, -light_source);   //invert the light vector so that they're both facing outwards
        if( d < 0 )
            d = 0;
        if( tt < t )
        {
            t = tt;
            closest = sphere;
        }
    }
    if( t == 1e6 )//miss
    {
        t = 1 + (r.dir.y() * 0.5);
        image.SetColor(y, x, (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0));

        //image.SetColor(y, x, Color(0,0,0));
    }
    else
        image.SetColor(y, x, closest.color);
    /*
    Sphere s = scene.Spheres[0];
    double t = s.hit(r);

    if( t <= 0 )    //doesn't hit
    {
        t = 1 + (r.dir.y() * 0.5);
        image.SetColor(y, x, (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0));
        return;
    }

    vec3 N = unit_vector(r.at(t) - s.center);
    N = unit_vector(N + vec3(1,1,1));
    point3 light_source = unit_vector(vec3(-1,-1,-1));
    double d = dot(N, -light_source);   //invert the light vector so that they're both facing outwards
    if( d < 0 )
        d = 0;
    /*
    c = 0.5 * (N + point3(1, 1, 1));
    c *= d*/
    //c = scene.Spheres[0].color;

    //image.SetColor(y, x, c);
}
