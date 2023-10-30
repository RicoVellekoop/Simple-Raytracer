#include "../include/floor.h"

Floor::Floor(float x, float y, float z, float length, float width, Material *m) : Object(x, y, z, m)
{
  this->length = length;
  this->width = width;
}

HitInfo Floor::hit(class Ray &ray) const
{
  float rayDistance = (center.y - ray.getSupVec().y) / ray.getDirVec().y; //  calculates how far the ray has to travel before hitting the floor
  if (rayDistance < 0)
  { //  returns false if the ray travels upwards
    return HitInfo();
  }
  Vec3D hitPoint = ray.getSupVec() + ray.getDirVec() * rayDistance; //  travels the rayDistance on the ray to reach the floor.

  if (abs(hitPoint.x - center.x) < length / 2 && abs(hitPoint.z - center.z) < width / 2)
  {
    return HitInfo(hitPoint, this->getNormalVector(ray), rayDistance, (Object *)this);
  };
  return HitInfo();
}

Vec3D Floor::hitPoint(class Ray &ray) const
{ //  calculates how far the ray has to travel before hitting the floor
  float rayDistance = (center.y - ray.getSupVec().y) / ray.getDirVec().y;
  return ray.getSupVec() + ray.getDirVec() * rayDistance;
}

Vec3D Floor::getNormalVector(class Ray &ray) const
{ //  returns a vector perpendicular to the floor
  return Vec3D(0, 1, 0);
}

Vec3D Floor::getCenter() const
{
  return center;
}

std::string Floor::getType()
{ //  Used to be able to know what object a ray has hit
  return "Floor";
}

Color Floor::getColor(HitInfo const &hitInfo) const
{
  float u = (hitInfo.hitPoint.x - center.x + length / 2) / length;
  float v = (hitInfo.hitPoint.z - center.z + width / 2) / width;

  return material->texture->value(u, v);
}