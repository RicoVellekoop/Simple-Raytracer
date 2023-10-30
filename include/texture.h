#ifndef H_TEXTURE
#define H_TEXTURE

#include "vec3d.h"
#include "color.h"

class Texture
{
public:
    virtual Color value(float u, float v) const = 0;
};

class SolidColor : public Texture
{
public:
    Color color_value;

    SolidColor(Color c) : color_value(c) {}

    SolidColor(float red, float green, float blue)
        : SolidColor(Color(red, green, blue)) {}

    Color value(float u, float v) const override;
};

class CheckerTexture : public Texture
{
public:
    Color odd;
    Color even;
    float textureScale;

    CheckerTexture(Color odd, Color even, float scale);

    Color value(float u, float v) const override;
};

class UVTexture : public Texture
{
public:
    UVTexture() {}

    Color value(float u, float v) const override
    {
        return Color(u, v, 0.0f);
    }
};

#endif