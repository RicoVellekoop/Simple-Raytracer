#ifndef H_COLOR
#define H_COLOR

#include "vec3d.h"

class Color
{
public:
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    Color operator+(Color const &other);
    Color operator-(Color const &other);
    Color operator-();
    Color operator*(float scalar);
    Color operator/(float scalar);
    Color operator*(Color const &other);
    Color operator/(Color const &other);
    Color operator+=(Color const &other);
    Color operator-=(Color const &other);
    Color operator*=(float scalar);
    Color operator/=(float scalar);
    Color operator*=(Color const &other);
    Color operator/=(Color const &other);
    bool operator==(Color const &other);
    bool operator!=(Color const &other);
};

#endif