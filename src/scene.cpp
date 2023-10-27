#include "../include/scene.h"

Scene::Scene(std::vector<Object *> objects)
{
    this->objects = objects;
}

Scene::Scene()
{
    this->objects = std::vector<Object *>();
}

void Scene::addObject(Object *object)
{
    this->objects.push_back(object);
}

void Scene::removeObject(Object *object)
{
    for (int i = 0; i < this->objects.size(); i++)
    {
        if (this->objects[i] == object)
        {
            free(this->objects[i]);
            this->objects.erase(this->objects.begin() + i);
            return;
        }
    }
}

void Scene::clearObjects()
{
    this->objects.clear();
}

void Scene::setObjects(std::vector<Object *> objects)
{
    this->setObjects(objects, true);
}

void Scene::setObjects(std::vector<Object *> objects, bool deleteOld)
{
    if (deleteOld)
    {
        this->clearObjects();
    }
    this->objects = objects;
}

void Scene::deleteObjects()
{
    for (int i = 0; i < this->objects.size(); i++)
    {
        free(this->objects[i]);
    }
    this->clearObjects();
}

Scene::~Scene()
{
    this->deleteObjects();
}