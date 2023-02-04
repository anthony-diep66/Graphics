#ifndef COLOR_H
#define COLOR_H

#include "Color.h"

#include <iostream>

struct Color 
{
public:
    double rgb[3];
public:
    Color(double r, double g, double b)
        :
        rgb{r,g,b} 
    {}

    Color() = default;

    double r() const { return rgb[0]; }
    double g() const { return rgb[1]; }
    double b() const { return rgb[2]; }

    double& operator[](int i) { return rgb[i]; };

    uint8_t blowupR() const { return static_cast<int>(255.999 * rgb[0]); }
    uint8_t blowupG() const { return static_cast<int>(255.999 * rgb[1]); }
    uint8_t blowupB() const { return static_cast<int>(255.999 * rgb[2]); }

    Color& operator+=(const Color &c)
    {
        rgb[0] += c.rgb[0];
        rgb[1] += c.rgb[1];
        rgb[2] += c.rgb[2];
        return *this;
    }

    Color& operator*=(const double t) 
    {
        rgb[0] *= t;
        rgb[1] *= t;
        rgb[2] *= t;
        return *this;
    }

    Color& operator/=(const double t)
    {
        return *this *= 1/t;
    }
};

#endif

