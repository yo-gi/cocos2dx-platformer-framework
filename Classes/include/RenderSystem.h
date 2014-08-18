#ifndef __RENDER_SYSTEM__
#define __RENDER_SYSTEM__

#include "shef.h"

class RenderSystem : public artemis::EntityProcessingsystem
{
private:
    artemis::ComponentMapper<RenderComponent> renderMapper;
    artemis::ComponentMapper<PositionComponent> positionMapper;

public:
    RenderSystem()
    {
        addComponentType<RenderComponent>();
        addComponentType<PositionComponent>();
    };

    virtual void initialize()
    {
        renderMapper.init(*world);
        positionMapper.init(*world);
    };

    virtual void processEntity(artemis::Entity &e)
    {
        
    }

};
