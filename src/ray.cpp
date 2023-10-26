#include "../include/ray.h"

//  This constructor uses 2 Vec3D objects instead of the 6 floats in the assignment because it is easier to work with
Ray::Ray(Vec3D supportVec, Vec3D directionVec, float brightness, VPO &objects) : supportVec(supportVec), directionVec(directionVec)
{
  directionVec = directionVec.unit();
  this->objects = objects;
  this->brightness = brightness;
}

//  This constructor is used by the rayscanner
Ray::Ray(float xStart, float yStart, float brightness, VPO &objects) : supportVec(0, 0, -3), directionVec(xStart, yStart, 3)
{
  directionVec = directionVec.unit();
  this->objects = objects;
  this->brightness = brightness;
}

float Ray::trace()
{
  if (brightness < pow(0.4, 4))
  { // Stops a ray when it has already reflected 4 times
    return brightness;
  }
  for (Object *obj : objects)
  {
    if (obj->hit(*this))
    {
      if (obj->getType() == "Sphere")
      {
        return 0.4 * brightness + Ray(obj->hitPoint(*this), this->reflect(obj->getNormalVector(*this)), brightness * 0.6, objects).trace();
      }
      else if (obj->getType() == "Floor")
      {
        return brightness;
      }
    }
    else
    {
    }
  }
  return 0.0;
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
  return this->getDirVec().sub(normalVec.mul(2.0 * this->getDirVec().dot(normalVec)));
}
