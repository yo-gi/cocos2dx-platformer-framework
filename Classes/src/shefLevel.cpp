#include "shefLevel.h"

USING_NS_CC;

Level::Level()
{
    /* ECS */
    world = new artemis::World();
    world->setDelta(0.016f);

    systemManager = world->getSystemManager();
    entityManager = world->getEntityManager();

    // Initialize new systems here
    movementSystem = (MovementSystem*)systemManager->setSystem(new MovementSystem());

    systemManager->initializeAll();

    /* Physics */
    pPixelsPerMeter = 32.0f;
    pGravity = -pPixelsPerMeter / 0.7f;
    pWorld = new b2World(b2Vec2(0.0f, pGravity));
    pWorld->SetAllowSleeping(true);
    pWorld->SetContinuousPhysics(true);

    listener = new ContactListener();
    pWorld->SetContactListener(listener);

    std::cout << "level constructor" << std::endl;
}

/* ECS */
void Level::processSystems()
{
    movementSystem->process();
}





