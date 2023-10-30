#include <cmath>
#include "../include/texture.h"

Color SolidColor::value(float u, float v) const
{
    return color_value;
}

CheckerTexture::CheckerTexture(Color odd, Color even, float scale)
{
    this->odd = odd;
    this->even = even;
    this->textureScale = scale;
}

Color CheckerTexture::value(float u, float v) const
{
    if (int(u * 2 * textureScale) % 2 == int(v * 2 * textureScale) % 2)
        return odd;
    else
        return even;
}