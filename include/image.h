#ifndef H_IMAGE
#define H_IMAGE

#include "color.h"
#include "texture.h"

#include <cstdint>

class Image
{
public:
    int width, height;
    Color *pixels;

    Image(int width, int height);

    uint8_t *toBytes();

    void setPixel(int x, int y, Color color);
    void setPixel(int x, int y, float value);

    void saveImage(const char *filename);
    void showImage();

    void loadTexture(const Texture *tex);
};

#endif