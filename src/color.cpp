#include "../include/color.h"

float clamp(float value)
{
    return value < 0 ? 0 : value > 1 ? 1
                                     : value;
}

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(float r, float g, float b)
{
    this->r = clamp(r);
    this->g = clamp(g);
    this->b = clamp(b);
}

Color Color::operator+(Color const &other)
{
    return Color(r + other.r, g + other.g, b + other.b);
}

Color Color::operator-(Color const &other)
{
    return Color(r - other.r, g - other.g, b - other.b);
}

Color Color::operator-()
{
    return Color(1.0f - r, 1.0f - g, 1.0f - b);
}

Color Color::operator*(float scalar)
{
    return Color(r * scalar, g * scalar, b * scalar);
}

Color Color::operator/(float scalar)
{
    return Color(r / scalar, g / scalar, b / scalar);
}

Color Color::operator*(Color const &other)
{
    return Color(r * other.r, g * other.g, b * other.b);
}

Color Color::operator/(Color const &other)
{
    return Color(r / other.r, g / other.g, b / other.b);
}

Color Color::operator+=(Color const &other)
{
    r += other.r;
    g += other.g;
    b += other.b;
    return *this;
}

Color Color::operator-=(Color const &other)
{
    r -= other.r;
    g -= other.g;
    b -= other.b;
    return *this;
}

Color Color::operator*=(float scalar)
{
    r *= scalar;
    g *= scalar;
    b *= scalar;
    return *this;
}

Color Color::operator/=(float scalar)
{
    r /= scalar;
    g /= scalar;
    b /= scalar;
    return *this;
}

Color Color::operator*=(Color const &other)
{
    r *= other.r;
    g *= other.g;
    b *= other.b;
    return *this;
}

Color Color::operator/=(Color const &other)
{
    r /= other.r;
    g /= other.g;
    b /= other.b;
    return *this;
}

bool Color::operator==(Color const &other)
{
    return r == other.r && g == other.g && b == other.b;
}

bool Color::operator!=(Color const &other)
{
    return r != other.r || g != other.g || b != other.b;
}
