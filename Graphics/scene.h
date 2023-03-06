#ifndef SURFACE_LIST
#define SURFACE_LIST

#include "surface.h"
#include "sphere.h"
#include <memory>
#include <vector>

class Scene : public Surface 
{
public: 
    std::vector<std::shared_ptr<Surface>> objects;

public:
    Scene() = default;
    Scene(std::shared_ptr<Surface> object);

    void clear();
    void add(std::shared_ptr<Surface> object);

    virtual bool hit(   const ray& r, 
                        double t_min, 
                        double t_max, 
                        hit_record& record) const override;
};


#endif