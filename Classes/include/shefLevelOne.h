#ifndef __LEVEL_ONE__
#define __LEVEL_ONE__


#include "shefLevel.h"

class LevelOne : public cocos2d::Scene
{
public:
    void update(float dt);

    /* Scene */
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(LevelOne);

    /* Level Management */
    Level* level;

    /* Resources */
    cocos2d::Sprite* shefSprite;

    void loadResources();
    void initAnimations();

};

#endif // __LEVEL_ONE__
