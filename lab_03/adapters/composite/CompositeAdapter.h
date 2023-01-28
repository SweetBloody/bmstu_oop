#ifndef COMPOSITEADAPTER_H
#define COMPOSITEADAPTER_H

#include <BaseAdapter.h>
#include <Composite.h>

class Composite;

class CompositeAdapter: public BaseAdapter
{
public:
    virtual ~CompositeAdapter() = default;

    void setAdaptee(std::vector<std::shared_ptr<BaseObject>> adaptee) { _adaptee = adaptee; }

    virtual void request() = 0;
protected:
    std::vector<std::shared_ptr<BaseObject>> _adaptee;
};

#endif // COMPOSITEADAPTER_H
