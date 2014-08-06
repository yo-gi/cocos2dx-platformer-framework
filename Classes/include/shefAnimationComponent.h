#ifndef __ANIMATION_COMPONENT__
#define __ANIMATION_COMPONENT__

#include "shef.h"

class AnimationComponent : public artemis::Component
{
    cocos2d::Animation* _animation;

    AnimationComponent(cocos2d::Animation* initAnimation)
    {
        _animation = initAnimation;
    };
};

#endif // __ANIMATION_COMPONENT__
