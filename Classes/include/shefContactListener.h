#ifndef __CONTACT_LISTENER__
#define __CONTACT_LISTENER__

#include <vector>

#include "shef.h"

struct shefContact
{
    b2Fixture *fixtureA;
    b2Fixture *fixtureB;
    bool operator==(const shefContact& other) const
    {
        return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
    }
};

class ContactListener : public b2ContactListener
{
public:
    ContactListener();
    ~ContactListener();

    virtual void beginContact(b2Contact* contact);
    virtual void endContact(b2Contact* contact);
    virtual void preSolve(b2Contact* contact, const b2Manifold* oldManifold);
    virtual void postSolve(b2Contact* contact, const b2ContactImpulse* impulse);

private:
    std::vector<shefContact> _contacts;
};

#endif // __CONTACT_LISTENER__
