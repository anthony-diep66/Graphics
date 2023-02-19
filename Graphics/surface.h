#ifndef SURFACES_H
#define SURFACES_H
#include "ray.h"
#include "memory"

struct hit_record
{
    point3 p;
    vec3 normal;
    double t;
};

class Surface
{
public:
    virtual double hit(const ray& r) const = 0;
};

#endif