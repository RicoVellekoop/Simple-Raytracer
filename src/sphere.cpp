#include "../include/sphere.h"

Sphere::Sphere(float x, float y, float z, float radius) : Object(x, y, z)
{
  this->radius = radius;
}

Vec3D Sphere::getCenter() const
{
  return center;
}

std::string Sphere::getType()
{ //  Used to be able to know what object a ray has hit
  return "Sphere";
}

float Sphere::distFromRay(Ray const &ray) const
{
  //  source: https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line

  return this->getCenter()
      .sub(ray.getSupVec())
      .sub(ray.getDirVec()
               .mul(this->getCenter()
                        .sub(ray.getSupVec())
                        .dot(ray.getDirVec())))
      .norm();
}

bool Sphere::hit(class Ray &ray) const
{
  if (this->hitPoint(ray).distToPoint(ray.getSupVec()) < 0.0001)
  { //  this is here to make sure the reflected ray wont reflect on the same Sphere
    return false;
  }
  if (this->distFromRay(ray) < radius)
  {
    if (this->hitPoint(ray).sub(ray.getSupVec()).dot(ray.getDirVec()) > 0)
    { //  Check if Sphere is behind the ray
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

Vec3D Sphere::hitPoint(class Ray &ray) const
{
  /*
    The hitpoint is calculated by taking the closest point to the center(source: https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line) and using
    The Pythagoras theorem to calculate how far back you should travel on the ray to get to the edge of the Sphere. The triangle used in the Pythagoras
    theorem here is between the center, the closest point to the center on the ray, and the point you want to calculate. This brings the formula
    sqrt(radius^2 - distFromRay^2)
  */

  float backtrackDistance = sqrt(pow(this->radius, 2) - pow(this->distFromRay(ray), 2));

  return this->getCenter().add(ray.getSupVec()
                                   .sub(this->getCenter())
                                   .sub(ray.getDirVec()
                                            .mul(ray.getSupVec()
                                                     .sub(this->getCenter())
                                                     .dot(ray.getDirVec()))) // closest point on the ray to the center
                                   .sub(ray.getDirVec().mul(backtrackDistance)));
}

Vec3D Sphere::getNormalVector(class Ray &ray) const
{ //  this returns a vector perpendicular to the surface on the sphere where it hits the circle
  return this->hitPoint(ray).sub(this->getCenter()).unit();
}
