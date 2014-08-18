#ifndef __RENDER_COMPONENT__
#define __RENDER_COMPONENT__

#include "shef.h"

class RenderComponent : Component
{
public:
    cocos2d::Sprite* _node;

    RenderComponent(cocos2d::Sprite* initNode)
    {
        _node = initNode;
    };
};

#endif
