#ifndef H_SPHERE
#define H_SPHERE

#include <iostream>
#include <vector>
#include <math.h>

#include "vec3d.h"
#include "object.h"

typedef std::vector<Object*> VPO;

#include "ray.h"

class Sphere : public Object{
  public:
    float radius;

  Sphere(float x, float y, float z, float radius);

  Vec3D getCenter() const;

  std::string getType();

  float distFromRay (Ray const &ray) const;

  bool hit(class Ray &ray) const;

  Vec3D hitPoint (class Ray &ray) const;

  Vec3D getNormalVector(class Ray &ray) const;
};
#endif
