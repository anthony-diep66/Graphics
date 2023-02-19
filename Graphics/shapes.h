#ifndef SHAPES_H
#define SHAPES_H
#include "ray.h"
#include "memory"

struct hit_record
{
    point3 p;
    vec3 normal;
    double t;
};

class Shape 
{
public:
    virtual double hit(const ray& r) const = 0;
};

#endif