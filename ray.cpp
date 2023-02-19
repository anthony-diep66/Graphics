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
    Sphere s(point3(0,0,-1), 0.5);
    s.color = Color(1,0,1);
    double t = s.hit(*this);
    if( t > 0 ) //hits
    {
        vec3 N = unit_vector(at(t) - vec3(0, 0, -1));
        point3 light_source = unit_vector(vec3(-1,-1,-1));
        double d = dot(N, -light_source);
        if( d < 0 )
            d = 0;
        //Color c = 0.5 * (N + point3(1, 1, 1));
        Color c = s.color;
        c *= d;
        return c;
    }
    else //doesn't hit
    {
        t = 1 + (dir.y() * 0.5);
        return (1.0-t) * Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
    }
    
}