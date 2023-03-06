#include "Graphics/scene.h"


//Scene::Scene() { };
Scene::Scene(std::shared_ptr<Surface> object)
{
    add(object);
}

void Scene::clear()
{
    objects.clear();
}

void Scene::add(std::shared_ptr<Surface> object)
{
    objects.push_back(object);
}
bool Scene::hit(const ray& r, double t_min, double t_max, hit_record& record) const
{
    hit_record temp_rec;
    bool has_hit = false;
    auto t_closest = t_max;

    for(const auto& object : objects)
    {
        if( object->hit(r, t_min, t_closest, temp_rec) )
        {
            has_hit = true;
            t_closest = temp_rec.t;
            record = temp_rec;
        }
    }

    return has_hit;
}