#include "Graphics/scene.h"

void Scene::Add_Sphere(point3 center, double r)
{
    Sphere s(center, r);
    Spheres.push_back(s);
}

void Scene::Set_Color(Color c, int idx)
{
    if( idx < 0 || idx >= Spheres.size() )
        return;
    Spheres[idx].color = c;
}