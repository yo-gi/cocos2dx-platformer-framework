#ifndef __LEVEL_H__
#define __LEVEL_H__

#pragma once

#include "shef.h"

#include "shefContactListener.h"

#include "shefMovementSystem.h"
//#include "shefAnimationSystem.h"

//#include "LevelObject.h"

class Level
{
public:
    Level();

    /* ECS */
    artemis::World* world;
    artemis::SystemManager* systemManager;
    artemis::EntityManager* entityManager;
    void processSystems();

    // Declare systems here
    MovementSystem* movementSystem;

    /* Physics */
    float pPixelsPerMeter;
    float pGravity;
    b2World* pWorld;
    ContactListener* listener;

    /* Resources */

    /* Scene */


};

#endif // __LEVEL_H__
