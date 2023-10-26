#include "../include/vec3d.h"

#include <math.h>
//  3d vector class
//  Note: this 3d vector uses x as width, y as hight, and z as depth

Vec3D::Vec3D(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Vec3D Vec3D::minus()
{
  return Vec3D(-this->x, -this->y, -this->z);
}

Vec3D Vec3D::add(Vec3D const &other)
{
  return Vec3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vec3D Vec3D::sub(Vec3D const &other)
{
  return Vec3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vec3D Vec3D::mul(float scalar)
{
  return Vec3D(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vec3D Vec3D::div(float scalar)
{
  return Vec3D(this->x / scalar, this->y / scalar, this->z / scalar);
}

float Vec3D::norm()
{
  return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vec3D Vec3D::unit()
{ //  divides vector by length of the vector to make a vector in the same direction, but with a length of 1
  return this->div(this->norm());
}

float Vec3D::dot(Vec3D const &other)
{
  return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vec3D Vec3D::cross(Vec3D const &other)
{
  return Vec3D(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
}

float Vec3D::distToPoint(Vec3D const &other)
{
  return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2) + pow(this->z - other.z, 2));
}
