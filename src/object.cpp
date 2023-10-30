#include "../include/object.h"

HitInfo::HitInfo(Vec3D hitPoint, Vec3D normalVector, float distance, Object *object)
{
    this->hitPoint = hitPoint;
    this->normalVector = normalVector;
    this->distance = distance;
    this->object = object;
    this->hit = true;
}

HitInfo::HitInfo()
{
    this->hit = false;
}

Object::Object(float x, float y, float z, Material *m) : center(x, y, z)
{
    material = m;
}
