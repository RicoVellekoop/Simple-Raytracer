#include "../include/rayscanner.h"
#include "rayscanner.h"

RayScanner::RayScanner(VPO &objects, float xResolution, float yResolution, float fovValue)
{
  this->objects = objects;
  this->xResolution = xResolution;
  this->yResolution = yResolution;
  fovScaler = 3 / tan((180 - fovValue) / 2 * 3.14159265358979323846 / 180.0); //  calculates how much the screen has to be scaled in order to reach the desired FOV
}

float RayScanner::normalizeXValue(int value)
{ //  returns x coordinate on a scale from -1 to 1
  return ((value - xResolution / 2) / (float)xResolution) * 2;
}

float RayScanner::normalizeYValue(int value)
{ //  returns x coordinate on a scale relative to the width of the screen
  return -((value - yResolution / 2) / (float)xResolution) * 2;
}

Image RayScanner::renderImage()
{
  Image image = Image(xResolution, yResolution);

  for (int y = 0; y < yResolution; y++)
  {
    for (int x = 0; x < xResolution; x++)
    {
      float brightness = Ray(normalizeXValue(x) * fovScaler, -normalizeYValue(y) * fovScaler, 1.0, objects).trace();
      image.setPixel(x, y, brightness);
    }
  }

  return image;
}
