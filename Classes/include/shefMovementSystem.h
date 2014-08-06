#ifndef __MOVEMENT_SYSTEM__
#define __MOVEMENT_SYSTEM__

#include "shef.h"

#include "shefPositionComponent.h"
#include "shefVelocityComponent.h"

class MovementSystem : public artemis::EntityProcessingSystem
{
private:
    artemis::ComponentMapper<VelocityComponent> velocityMapper;
    artemis::ComponentMapper<PositionComponent> positionMapper;

public:
    MovementSystem()
    {
        addComponentType<VelocityComponent>();
        addComponentType<PositionComponent>();
    };

    virtual void initialize()
    {
        velocityMapper.init(*world);
        positionMapper.init(*world);
    };

    virtual void processEntity(artemis::Entity &e)
    {
        positionMapper.get(e)->_position.x += velocityMapper.get(e)->_velocity.x * world->getDelta();
        positionMapper.get(e)->_position.y += velocityMapper.get(e)->_velocity.y * world->getDelta();
    };
};

#endif // __MOVEMENT_SYSTEM__