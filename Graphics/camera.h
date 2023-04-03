#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
struct Camera
{
public:
    double viewport_height;
    double viewport_width;
    double focal_length;
    double aspect_ratio;
    vec3 origin;
    vec3 horizontal;
    vec3 vertical;
    vec3 lower_left_corner;
public:
    Camera();
    ray get_ray(double u, double v) const;
};
#endif