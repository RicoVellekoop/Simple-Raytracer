#ifndef H_RAY
#define H_RAY

#include <vector>
#include <math.h>

#include "vec3d.h"
#include "object.h"

typedef std::vector<Object *> VPO;

class Ray
{
public:
  float brightness;
  Vec3D supportVec, directionVec;
  VPO objects;

  Ray(Vec3D supportVec, Vec3D directionVec, float brightness, VPO &objects);

  Ray(float xStart, float yStart, float brightness, VPO &objects);

  float trace();

  Vec3D getSupVec() const;

  Vec3D getDirVec() const;

  Vec3D reflect(Vec3D normalVec) const;
};
#endif
