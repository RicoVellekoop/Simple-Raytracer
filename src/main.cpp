#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

#include "../include/vec3d.h"
#include "../include/object.h"

typedef std::vector<Object *> VPO;

#include "../include/ray.h"
#include "../include/floor.h"
#include "../include/sphere.h"
#include "../include/Rayscanner.h"

int main()
{
  VPO objects(4, NULL);
  Sphere s[3] = {Sphere(-0.4, 0.23, -1, 0.4), Sphere(0.4, 0.4, -1.2, 0.3), Sphere(0.7, -0.15, -1.5, 0.2)};
  Floor floor = Floor(0, -0.7, -2.3, 5, 5, 0.4);
  objects[0] = &s[0];
  objects[1] = &s[1];
  objects[2] = &s[2];
  objects[3] = &floor;

  RayScanner(objects, 1280, 720, 75).renderImage().saveImage("output.bmp");
  std::cout << "File saved as output.bmp" << std::endl;
  return 0;
}
