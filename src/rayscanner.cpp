#include "../include/rayscanner.h"
#include "rayscanner.h"

#include <thread>
#include <vector>

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

void processRows(int start, int end, RayScanner &scanner, Image &image)
{
  for (int y = start; y < end; y++)
  {
    for (int x = 0; x < scanner.xResolution; x++)
    {
      float brightness = Ray(scanner.normalizeXValue(x) * scanner.fovScaler, -scanner.normalizeYValue(y) * scanner.fovScaler, 1.0, scanner.objects).trace();
      image.setPixel(x, y, brightness);
    }
  }
}

Image RayScanner::renderImage()
{
  Image image = Image(xResolution, yResolution);
  int numThreads = std::thread::hardware_concurrency();

  std::vector<std::thread> threads;
  int rowsPerThread = yResolution / numThreads;
  int start = 0;
  int end = rowsPerThread;
  for (int i = 0; i < numThreads; i++)
  {
    if (i == numThreads - 1)
    {
      end = yResolution;
    }
    threads.emplace_back(processRows, start, end, std::ref(*this), std::ref(image));
    start = end;
    end += rowsPerThread;
  }
  for (auto &thread : threads)
  {
    thread.join();
  }

  return image;
}
