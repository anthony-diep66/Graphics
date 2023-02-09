#ifndef SPHERE_H
#define SPHERE_H
#include "shapes.h"
#include "vec3.h"

class Sphere : public Shape 
{
public: 
    point3 center;
    double radius;
public:
    Sphere() = default;
    Sphere(point3 center, double r)
        :
        center(center), radius(r)
    {}
    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override; 
};

bool Sphere::hit(const ray& r, double tmin, double tmax, hit_record& rec) const 
{

}

#endif