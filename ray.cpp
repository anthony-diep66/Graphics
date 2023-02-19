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
//unused
extern Color ray::ray_color()
{   }