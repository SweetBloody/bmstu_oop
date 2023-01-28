#ifndef SCENE_H
#define SCENE_H

#include <Composite.h>
#include <Camera.h>
#include <Point.h>

class BaseObject;

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    std::size_t addObject(const std::shared_ptr<BaseObject> &object);
    std::size_t addCamera(const Point &location, const Point &direction);
    void deleteObject(Iterator &iter);

    Iterator getObjectIter(const std::size_t id);
    std::shared_ptr<BaseObject> getObject(const std::size_t id);
    std::vector<std::shared_ptr<BaseObject>> getObjects();

    Iterator begin();
    Iterator end();

protected:
    std::vector<std::shared_ptr<BaseObject>> _objects;
};

#endif //SCENE_H
