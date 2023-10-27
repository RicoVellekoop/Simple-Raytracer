#ifndef H_SCENE
#define H_SCENE

#include <vector>

#include "object.h"

typedef std::vector<Object *> VPO;

class Scene
{
public:
    VPO objects;

    Scene();
    Scene(std::vector<Object *> objects);
    void addObject(Object *object);
    void removeObject(Object *object);
    void clearObjects();
    void setObjects(std::vector<Object *> objects);
    void setObjects(std::vector<Object *> objects, bool deleteOld);
    void deleteObjects();
    ~Scene();
};

#endif