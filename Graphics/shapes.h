#ifndef SHAPES_H
#define SHAPES_H
#include "ray.h"

struct hit_record
{
    point3 p;
    vec3 normal;
    double t;
};

class Shape 
{
public:
    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const = 0;
};

#endif