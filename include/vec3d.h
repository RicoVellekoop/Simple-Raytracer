#ifndef H_VEC3d
#define H_VEC3d

class Vec3D{

  public:
  float x, y, z;

  Vec3D(float x, float y, float z);

  Vec3D minus ();

  Vec3D add (Vec3D const &other);

  Vec3D sub (Vec3D const &other);

  Vec3D mul (float scalar);

  Vec3D div (float scalar);

  float norm ();

  Vec3D unit ();

  float dot (Vec3D const &other);

  Vec3D cross (Vec3D const &other);

  float distToPoint(Vec3D const &other);
};
#endif
