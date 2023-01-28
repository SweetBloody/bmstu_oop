#include <iterator>

#include <Scene.h>
#include <Composite.h>

#include <QDebug>

std::size_t Scene::addObject(const std::shared_ptr<BaseObject> &object)
{
    _objects.push_back(object);

    return object->getId();
}

std::size_t Scene::addCamera(const Point &location, const Point &direction)
{
    auto camera = std::make_shared<Camera>(Camera(location, direction));
    _objects.push_back(camera);

    return camera->getId();
}

void Scene::deleteObject(Iterator &iter)
{
    _objects.erase(iter);
}

Iterator Scene::getObjectIter(const std::size_t id)
{
    auto iter = begin();

    for (; iter != end() && (*iter)->getId() != id; ++iter);

    return iter;
}

std::shared_ptr<BaseObject> Scene::getObject(const std::size_t id)
{
    return *getObjectIter(id);
}

std::vector<std::shared_ptr<BaseObject>> Scene::getObjects()
{
    return _objects;
}

Iterator Scene::begin()
{
    return _objects.begin();
}

Iterator Scene::end()
{
    return _objects.end();
}
