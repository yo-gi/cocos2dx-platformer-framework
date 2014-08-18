#include "shefContactListener.h"

ContactListener::ContactListener() {}
ContactListener::~ContactListener() {}

void ContactListener::beginContact(b2Contact* contact)
{
    shefContact newContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    _contacts.push_back(newContact);
}

void ContactListener::endContact(b2Contact* contact)
{
    shefContact newContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    std::vector<shefContact>::iterator it;
    it = std::find(_contacts.begin(), _contacts.end(), newContact);
    if (it != _contacts.end())
    {
        _contacts.erase(it);
    }
}

void ContactListener::preSolve(b2Contact* contact, 
                                   const b2Manifold* oldManifold) {}

void ContactListener::postSolve(b2Contact* contact,
                                    const b2ContactImpulse* impulse) {}
