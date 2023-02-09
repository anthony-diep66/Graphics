#include "Graphics/ray.h"
#include "Graphics/sphere.h"
#include <cmath>

double hit_sphere(const point3& center, double radius, const ray& r);

ray::ray() = default;
ray::ray(const point3& origin, const vec3& direction)
    :
    orig(origin), dir(direction)
{}

point3 ray::origin() const 
{
    return orig;
}

vec3 ray::direction() const 
{
    return dir;
}

point3 ray::at(double t) const 
{
    return orig + t * dir;
}
extern Color ray::ray_color()
{
    double t = hit_sphere(point3(0,0,-1),0.5,*this);
    if( t > 0 )
    {
        vec3 N = unit_vector(at(t) - vec3(0, 0, -1));
        point3 light_source = unit_vector(vec3(-1,-1,-1));
        double d = dot(N, -light_source);
        if( d < 0 )
            d = 0;
        /*
        Color sphere_color(1, 0, 1);
        sphere_color *= d; 
        return sphere_color;
        */
        Color c = 0.5 * (N + point3(1, 1, 1));
        c *= d;
        return c;

    }
    else
    {
        //"linear interpolation or lerp"
        // t = 1 -> all blue : t = 0 -> all white. Everything in between is a linear blend
        //lerp in form: Value(t) = (1 - t) * start_color + t * end_color
        //return (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
        return Color(0,0,0);
    }
    
}

double hit_sphere(const point3& center, double radius, const ray& r)
{
    vec3 sphere_center = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(sphere_center, r.direction());
    auto c = dot(sphere_center, sphere_center) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if( discriminant < 0 )
        return -1.0;
    return (-b - sqrt(discriminant)) / (2 * a);
}

