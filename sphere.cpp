#include "Graphics/sphere.h"

Sphere::Sphere() = default;
Sphere::Sphere(point3 center, double r)
    :
    center(center), radius(r)
{}

bool Sphere::hit(const ray& r, double t_min, double t_max, hit_record& record) const
{
    vec3 sphere_center = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(sphere_center, r.direction());
    auto c = dot(sphere_center, sphere_center) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if( discriminant < 0 )
        return false;
    double sqrt_d = sqrt(discriminant); 
    double t = (-b - sqrt(discriminant)) / (2 * a);
    if( t < t_min || t_max < t )
    {
        t = (-b + sqrt(discriminant)) / (2 * a);
        if( t < t_min || t_max < t )
            return false;
    }
    record.t = t;
    record.p = r.at(record.t);

    vec3 outward_normal = (record.p - center) / radius;
    record.set_face_normal(r, outward_normal);
    return true;
}

