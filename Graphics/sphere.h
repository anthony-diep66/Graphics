#ifndef SPHERE_H
#define SPHERE_H
#include "surface.h"
#include "vec3.h"

class Sphere : public Surface
{
public: 
    point3 center;
    double radius;
    Color color;
public:
    Sphere();
    Sphere(point3 center, double r);
    virtual double hit(const ray& r) const override; 
};


#endif