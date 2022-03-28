#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>



#include "vec3d.h"
#include "object.h"

typedef std::vector<Object*> VPO;

#include "ray.h"
#include "floor.h"
#include "sphere.h"
#include "Rayscanner.h"



int main(){
  VPO objects(4, NULL);
  Sphere s[3] = {Sphere (-0.4, 0.23, -1, 0.4), Sphere (0.4, 0.4, -1.2, 0.3), Sphere (0.7, -0.15, -1.5, 0.2)};
  Floor floor = Floor(0, -0.7, -2.3, 5, 5, 0.4);
  objects[0] = &s[0];
  objects[1] = &s[1];
  objects[2] = &s[2];
  objects[3] = &floor;

  RayScanner(objects, 80, 40, 75).scan();
  RayScanner(objects, 1280, 720, 75).renderImage(1.0, 1.0, 1.0);
  return 0;
}
