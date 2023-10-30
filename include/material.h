#ifndef H_MATERIAL
#define H_MATERIAL

#include "texture.h"

class Material
{
public:
    Texture *texture;

    Material(Texture *t) : texture(t) {}
};

#endif