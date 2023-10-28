#include "../include/vec3d.h"

#include <math.h>
//  3d vector class
//  Note: this 3d vector uses x as width, y as hight, and z as depth

Vec3D::Vec3D()
{
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

Vec3D::Vec3D(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Vec3D Vec3D::operator+(Vec3D const &other)
{
  return Vec3D(x + other.x, y + other.y, z + other.z);
}

Vec3D Vec3D::operator-(Vec3D const &other)
{
  return Vec3D(x - other.x, y - other.y, z - other.z);
}

Vec3D Vec3D::operator-()
{
  return Vec3D(-x, -y, -z);
}

Vec3D Vec3D::operator*(float scalar)
{
  return Vec3D(x * scalar, y * scalar, z * scalar);
}

Vec3D Vec3D::operator/(float scalar)
{
  return Vec3D(x / scalar, y / scalar, z / scalar);
}

Vec3D Vec3D::operator*(Vec3D const &other)
{
  return Vec3D(x * other.x, y * other.y, z * other.z);
}

Vec3D Vec3D::operator/(Vec3D const &other)
{
  return Vec3D(x / other.x, y / other.y, z / other.z);
}

Vec3D Vec3D::operator+=(Vec3D const &other)
{
  return *this = *this + other;
}

Vec3D Vec3D::operator-=(Vec3D const &other)
{
  return *this = *this - other;
}

Vec3D Vec3D::operator*=(float scalar)
{
  return *this = *this * scalar;
}

Vec3D Vec3D::operator/=(float scalar)
{
  return *this = *this / scalar;
}

Vec3D Vec3D::operator*=(Vec3D const &other)
{
  return *this = *this * other;
}

Vec3D Vec3D::operator/=(Vec3D const &other)
{
  return *this = *this / other;
}

bool Vec3D::operator==(Vec3D const &other)
{
  return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vec3D::operator!=(Vec3D const &other)
{
  return this->x != other.x || this->y != other.y || this->z != other.z;
}

float Vec3D::norm()
{
  return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vec3D Vec3D::unit()
{ //  divides vector by length of the vector to make a vector in the same direction, but with a length of 1
  float length = this->norm();
  return Vec3D(this->x / length, this->y / length, this->z / length);
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
