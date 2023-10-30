#ifndef H_OBJECT
#define H_OBJECT

#include <iostream>
#include "vec3d.h"
#include "material.h"

class Object;

class HitInfo
{
public:
  Vec3D hitPoint;
  Vec3D normalVector;
  float distance;
  Object *object;
  bool hit;

  HitInfo(Vec3D hitPoint, Vec3D normalVector, float distance, Object *object);
  HitInfo();
};

class Object
{
public:
  Vec3D center;
  Material *material;

  Object(float x, float y, float z, Material *m);

    virtual bool hit(class Ray &ray) const = 0;
    virtual Vec3D hitPoint(class Ray &ray) const = 0;
    virtual Vec3D getNormalVector(class Ray &ray) const = 0;
    virtual std::string getType() = 0;
};
#endif
