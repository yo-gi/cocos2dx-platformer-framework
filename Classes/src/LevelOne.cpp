#include "shefLevelOne.h"

#include <iostream>

USING_NS_CC;

/* Scene */
Scene* LevelOne::createScene()
{
    auto scene = Scene::create();
    auto layer = LevelOne::create();
    scene->addChild(layer);

    return scene;
}

bool LevelOne::init()
{

    if (!Scene::init()) return false;

    this->schedule(schedule_selector(LevelOne::update));
    return true;

    level = new Level();
    loadResources();

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    MoveTo* act1 = MoveTo::create(0.5, Point(200, 200));
    shefSprite->runAction(Repeat::create(act1, 1));

    return true;
}

void LevelOne::update(float dt)
{
    level->world->loopStart();
    level->processSystems();
}

/* Resources */
void LevelOne::loadResources()
{
    auto cache = SpriteFrameCache::getInstance();

    cache->addSpriteFramesWithFile("ragna.plist", "ragna.png");
    shefSprite = Sprite::createWithSpriteFrameName("rg000_00.png");

    Vector<SpriteFrame*> frames;
    for (int i = 0; i < 7; ++i)
    {
        std::stringstream ss;
        ss << "rg000_0" << i << ".png";
        std::cout << "Loading " << ss.str() << "\n";
        frames.pushBack(cache->getSpriteFrameByName(ss.str().c_str()));
    }

    Animation* animation = Animation::createWithSpriteFrames(frames, 0.016f);
    // shefSprite->runAction( RepeatForever::create( Animate::create(animation) ) );
    shefSprite->runAction( Animate::create( animation ) );
    shefSprite->setAnchorPoint(Point(0,0));
    shefSprite->setPosition(Point(0, 0));
    this->addChild(shefSprite, 0);
    std::cout << "levelone loadresources end" << std::endl;
}

void LevelOne::initAnimations()
{
    
}
