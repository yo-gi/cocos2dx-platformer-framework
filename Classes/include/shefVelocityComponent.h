#ifndef __VELOCITY_COMPONENT__
#define __VELOCITY_COMPONENT__

#include "shef.h"

class VelocityComponent : public artemis::Component
{
public:
    cocos2d::Vec2 _velocity;

    VelocityComponent(cocos2d::Vec2 initVelocity)
    {
        _velocity = initVelocity;
    };

};

#endif // __VELOCITY_COMPONENT__
