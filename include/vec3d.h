#ifndef H_VEC3d
#define H_VEC3d

class Vec3D
{

public:
  float x, y, z;
  Vec3D();
  Vec3D(float x, float y, float z);
  Vec3D operator+(Vec3D const &other);
  Vec3D operator-(Vec3D const &other);
  Vec3D operator-();
  Vec3D operator*(float scalar);
  Vec3D operator/(float scalar);
  Vec3D operator*(Vec3D const &other);
  Vec3D operator/(Vec3D const &other);
  Vec3D operator+=(Vec3D const &other);
  Vec3D operator-=(Vec3D const &other);
  Vec3D operator*=(float scalar);
  Vec3D operator/=(float scalar);
  Vec3D operator*=(Vec3D const &other);
  Vec3D operator/=(Vec3D const &other);
  bool operator==(Vec3D const &other);
  bool operator!=(Vec3D const &other);
  float norm();
  Vec3D unit();
  float dot(Vec3D const &other);
  Vec3D cross(Vec3D const &other);
  float distToPoint(Vec3D const &other);
};
#endif
