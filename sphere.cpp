#include "Graphics/sphere.h"

Sphere::Sphere() = default;
Sphere::Sphere(point3 center, double r)
    :
    center(center), radius(r)
{}

double Sphere::hit(const ray& r) const
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