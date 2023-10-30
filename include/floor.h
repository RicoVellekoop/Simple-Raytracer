#ifndef H_FLOOR
#define H_FLOOR

#include "vec3d.h"
#include "object.h"
#include "ray.h"

class Floor : public Object
{
public:
  float length, width;
  Floor(float x, float y, float z, float length, float width, Material *m);
  Vec3D hitPoint(class Ray &ray) const;
  Vec3D getNormalVector(class Ray &ray) const;
  Vec3D getCenter() const;
  std::string getType();
};
#endif
