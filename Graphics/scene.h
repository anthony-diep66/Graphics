#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "sphere.h"

struct Scene 
{
    std::vector<Sphere> Spheres;
    void Add_Sphere(point3 center, double r);
    void Set_Color(Color c, int idx);
};

#endif