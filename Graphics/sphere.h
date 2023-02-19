#ifndef SPHERE_H
#define SPHERE_H
#include "shapes.h"
#include "vec3.h"

class Sphere : public Shape 
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