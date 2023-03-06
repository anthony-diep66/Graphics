#include "Graphics/surface_list.h"


SurfaceList::SurfaceList() = default;
SurfaceList::SurfaceList(std::shared_ptr<Surface> object)
{
    add(object);
}

void SurfaceList::clear()
{
    objects.clear();
}

void SurfaceList::add(std::shared_ptr<Surface> object)
{
    objects.push_back(object);
}
bool SurfaceList::hit(const ray& r, double t_min, double t_max, hit_record& record) const
{
    hit_record temp_rec;
    bool has_hit = false;
    bool t_closest = t_max;

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