#include "../include/ray.h"
#include <mutex>

//  This constructor uses 2 Vec3D objects instead of the 6 floats in the assignment because it is easier to work with
Ray::Ray(Vec3D supportVec, Vec3D directionVec, Color color, VPO &objects) : supportVec(supportVec), directionVec(directionVec)
{
  directionVec = directionVec.unit();
  this->objects = objects;
  this->color = color;
}

//  This constructor is used by the rayscanner
Ray::Ray(float xStart, float yStart, Color color, VPO &objects) : supportVec(0, 0, -3), directionVec(xStart, yStart, 3)
{
  directionVec = directionVec.unit();
  this->objects = objects;
  this->color = color;
}

Color Ray::trace(int depth)
{
  if (depth > 4)
  { // Stops a ray when it has already reflected 4 times
    return color;
  }
  HitInfo closestHit = HitInfo();

  for (Object *obj : objects)
  {
    HitInfo hit = obj->hit(*this);
    if (hit.hit && (!closestHit.hit || hit.distance < closestHit.distance))
    {
      closestHit = hit;
    }
  }
  if (closestHit.hit)
  {
    if (closestHit.object->getType() == "Sphere")
    {
      return closestHit.object->getColor(closestHit) * 0.4 + Ray(closestHit.hitPoint, this->reflect(closestHit.normalVector), color * 0.6, objects).trace(depth + 1);
    }
    else if (closestHit.object->getType() == "Floor")
    {
      return closestHit.object->getColor(closestHit);
    }
  }
  return Color(0, 0, 0);
}

Vec3D Ray::getSupVec() const
{
  return supportVec;
}

Vec3D Ray::getDirVec() const
{
  return directionVec;
}

Vec3D Ray::reflect(Vec3D normalVec) const
{ //  mirrors a directionVec in a vector which is perpendicular to the surface of the object
  //  source: https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/reflect.xhtml
  return this->getDirVec() - normalVec * (2.0 * this->getDirVec().dot(normalVec));
}
