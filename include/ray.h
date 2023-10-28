#ifndef H_RAY
#define H_RAY

#include <vector>
#include <math.h>

#include "vec3d.h"
#include "object.h"
#include "color.h"

typedef std::vector<Object *> VPO;

class Ray
{
public:
  Color color;
  Vec3D supportVec, directionVec;
  VPO objects;

  Ray(Vec3D supportVec, Vec3D directionVec, Color color, VPO &objects);

  Ray(float xStart, float yStart, Color color, VPO &objects);

  Color trace(int depth);

  Vec3D getSupVec() const;

  Vec3D getDirVec() const;

  Vec3D reflect(Vec3D normalVec) const;
};
#endif
