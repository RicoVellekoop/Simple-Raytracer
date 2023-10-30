#include "../include/sphere.h"

Sphere::Sphere(float x, float y, float z, float radius, Material *m) : Object(x, y, z, m)
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

  return (this->getCenter() - ray.getSupVec() - ray.getDirVec() * ((this->getCenter() - ray.getSupVec()).dot(ray.getDirVec()))).norm();
}

HitInfo Sphere::hit(class Ray &ray) const
{
  Vec3D hitPoint = this->hitPoint(ray);
  float distance = hitPoint.distToPoint(ray.getSupVec());

  if (this->distFromRay(ray) < radius && (hitPoint - ray.getSupVec()).dot(ray.getDirVec()) > 0 && distance > 0.0001)
  { //  Check if Sphere is behind the ray and if the distance is not 0
    return HitInfo(hitPoint, this->getNormalVector(ray), hitPoint.distToPoint(ray.getSupVec()), (Object *)this);
  }
  return HitInfo();
}

Vec3D Sphere::hitPoint(class Ray &ray) const
{
  /*
    The hit-point is calculated by taking the closest point to the center(source: https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line) and using
    The Pythagoras theorem to calculate how far back you should travel on the ray to get to the edge of the Sphere. The triangle used in the Pythagoras
    theorem here is between the center, the closest point to the center on the ray, and the point you want to calculate. This brings the formula
    sqrt(radius^2 - distFromRay^2)
  */

  float backtrackDistance = sqrt(pow(this->radius, 2) - pow(this->distFromRay(ray), 2));

  return this->getCenter() + (ray.getSupVec() - this->getCenter() - ray.getDirVec() * (ray.getSupVec() - this->getCenter()).dot(ray.getDirVec()) // closest point on the ray to the center
                              - ray.getDirVec() * backtrackDistance);
}

Vec3D Sphere::getNormalVector(class Ray &ray) const
{ //  this returns a vector perpendicular to the surface on the sphere where it hits the circle
  return (this->hitPoint(ray) - this->getCenter()).unit();
}

Color Sphere::getColor(HitInfo const &hitInfo) const
{
  float u = 0.5 + atan2(hitInfo.hitPoint.z - center.z, hitInfo.hitPoint.x - center.x) / (2 * M_PI);
  float v = 0.5 - asin(hitInfo.hitPoint.y - center.y) / M_PI;

  return material->texture->value(u, v);
}
