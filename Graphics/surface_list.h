#ifndef SURFACE_LIST
#define SURFACE_LIST

#include "surface.h"
#include <memory>
#include <vector>

class SurfaceList : public Surface 
{
public: 
    std::vector<std::shared_ptr<Surface>> objects;

public:
    SurfaceList();
    SurfaceList(std::shared_ptr<Surface> object);

    void clear();
    void add(std::shared_ptr<Surface> object);

    virtual bool hit(   const ray& r, 
                        double t_min, 
                        double t_max, 
                        hit_record& record) const override;
};


#endif