#ifndef H_OBJECT
#define H_OBJECT

#include <iostream>
#include "vec3d.h"

class Object{
  public:
    Vec3D center;

    Object (float x, float y, float z);

    virtual bool hit(class Ray &ray) const = 0;
    virtual Vec3D hitPoint(class Ray &ray) const = 0;
    virtual Vec3D getNormalVector(class Ray &ray) const = 0;
    virtual std::string getType() = 0;
};
#endif
