#include "../include/image.h"

#include <iostream>
#include <fstream>
#include "image.h"

static const char asciiPallet[8] = {' ', '.', ',', '\"', '/', 'O', '8', '@'};

#define BMP_HEADER_SIZE 54
uint8_t *generateHeader(int width, int height)
{
    //  This is a standard header for a simple bmp file, with the resolution filled in
    uint8_t *bmpHeader = new uint8_t[BMP_HEADER_SIZE]{66, 77, 70, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, (unsigned char)(width % 256), (unsigned char)(width / 255), 0, 0, (unsigned char)(height % 256), (unsigned char)(height / 255), 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    return bmpHeader;
}

uint8_t *Image::toBytes()
{
    uint8_t *bytes = new uint8_t[width * height * 3];

    for (int i = 0; i < width * height; i++)
    {
        bytes[i * 3] = (uint8_t)(pixels[i] * 255);
        bytes[i * 3 + 1] = (uint8_t)(pixels[i] * 255);
        bytes[i * 3 + 2] = (uint8_t)(pixels[i] * 255);
    }

    return bytes;
}

char *Image::toAscii()
{
    char *ascii = new char[width * height];

    for (int i = 0; i < width * height; i++)
    {
        ascii[i] = asciiPallet[(int)(pixels[i] * (sizeof asciiPallet / sizeof asciiPallet[0]))];
    }

    return ascii;
}

Image::Image(int width, int height)
{
    this->width = width;
    this->height = height;
    pixels = new float[width * height];
}

void Image::setPixel(int x, int y, float value)
{
    pixels[y * width + x] = value;
}

void Image::saveImage(const char *filename)
{
    int padding = (4 - width * 3 % 4) % 4;
    uint8_t *bytes = toBytes();
    uint8_t *header = generateHeader(width, height);

    std::ofstream outputFile;
    outputFile.open(filename, std::ios::binary);

    outputFile.write(reinterpret_cast<const char *>(header), BMP_HEADER_SIZE);

    for (int y = 0; y < height; y++)
    {
        outputFile.write(reinterpret_cast<const char *>(&bytes[y * width * 3]), width * 3);
        for (int i = 0; i < padding; i++)
        {
            outputFile.write("\0", 1);
        }
    }
    outputFile << toBytes();

    delete[] bytes;
    delete[] header;
    outputFile.close();
}

void Image::showImage()
{
    char *ascii = toAscii();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::cout << ascii[y * width + x];
            std::cout << ascii[y * width + x];
        }
        std::cout << std::endl;
    }
}
