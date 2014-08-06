#ifndef __LEVEL_OBJECT__
#define __LEVEL_OBJECT__

#include "Artemis.h"
#include "cocos2d.h"

class LevelObject : public cocos2d::Node, public artemis::Entity
{
private:
    typedef Node super;
    typedef LevelObject self;

protected:
    b2Body* body;
    cocos2s::Sprite* sprite;
    artemis::Entity* entity;

public:
    LevelObject();
    virtual ~LevelObject();
};

#endif // __LEVEL_OBJECT__
