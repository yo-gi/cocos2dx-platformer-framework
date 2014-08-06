#ifndef __POSITION_COMPONENT__
#define __POSITION_COMPONENT__

#include "shef.h"

class PositionComponent : public artemis::Component
{
public:
    cocos2d::Vec2 _position;

    PositionComponent(cocos2d::Vec2 initPosition)
    {
        _position = initPosition; 
    };
};

#endif // __POSITION_COMPONENT__
