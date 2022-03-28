#include "floor.h"


  Floor::Floor(float x, float y, float z, float length, float width, float checkerDistance):Object(x,y,z){
    this -> length = length;
    this -> width = width;
    this -> checkerDistance = checkerDistance;
  }



  bool Floor::hit (class Ray &ray) const{
    float rayDistance = (center.y - ray.getSupVec().y) / ray.getDirVec().y; //  calculates how far the ray has to travel before hitting the floor
    if(rayDistance < 0){  //  returns false if the ray travels upwards
      return false;
    }
    Vec3D hitPoint = ray.getSupVec().add(ray.getDirVec().mul(rayDistance)).sub(this -> getCenter());  //  travels the rayDistance on the ray to reach the floor.

    if(abs(hitPoint.x) > length/2 || abs(hitPoint.z) > width/2){  //  returns false if the hitPoint is not on the floor
      return false;
    }

    bool xOffset = (hitPoint.x < 0);  //  this is used to remove a unstaggered row on the place where the x coördinate goes below 0
    bool zOffset = (hitPoint.z < 0);  //  this is used to remove a unstaggered row on the place where the z coördinate goes below 0

    //  calculates which what square the ray hits counted from the middle. if the X and Z coörniates of that square are either both even or both uneven this will return true
    return (int)(abs(hitPoint.x -xOffset*checkerDistance)/checkerDistance)%2 == (int)((abs(hitPoint.z -zOffset*checkerDistance))/checkerDistance)%2;
  }

  Vec3D Floor::hitPoint(class Ray &ray) const{ //  calculates how far the ray has to travel before hitting the floor
    float rayDistance = (center.y - ray.getSupVec().y) / ray.getDirVec().y;
    return ray.getSupVec().add(ray.getDirVec().mul(rayDistance));
  }

  Vec3D Floor::getNormalVector(class Ray &ray) const{  //  returns a vector perpendicular to the floor
    return Vec3D(0, 1, 0);
  }

  Vec3D Floor::getCenter() const{
    return center;
  }

  std::string Floor::getType(){  //  Used to be able to know what object a ray has hit
    return "Floor";
  }
