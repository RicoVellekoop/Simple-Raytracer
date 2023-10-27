#include <iostream>

#include "../include/floor.h"
#include "../include/sphere.h"
#include "../include/rayscanner.h"
#include "../include/scene.h"

int main()
{
  Scene scene = Scene();
  scene.addObject(new Sphere(-0.4, 0.23, -1, 0.4));
  scene.addObject(new Sphere(0.4, 0.4, -1.2, 0.3));
  scene.addObject(new Sphere(0.7, -0.15, -1.5, 0.2));
  scene.addObject(new Floor(0, -0.7, -2.3, 5, 5, 0.4));

  RayScanner(scene, 1280, 720, 75).renderImage().saveImage("output.bmp");
  std::cout << "File saved as output.bmp" << std::endl;
  return 0;
}
