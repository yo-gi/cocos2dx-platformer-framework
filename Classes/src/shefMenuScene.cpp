#include "shefMenuScene.h"
#include "shefLevelOne.h"

#include <iostream>

USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init()
{
//    if ( !Layer::init() ) { return false; }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto levelOneButton = MenuItemImage::create(
        "level_one_button.png",
        "level_one_button_selected.png",
        CC_CALLBACK_1(MenuScene::levelOneCallback, this));

    levelOneButton->setPosition(visibleSize.width/2, 600);

    auto menu = Menu::create(levelOneButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    std::cout << "menuscene init" << std::endl;

    return true;
}

void MenuScene::levelOneCallback(Ref* pSender)
{
//    LevelOne* levelOne = new LevelOne();
//    auto newScene = levelOne->createScene();
    LevelOne levelOne;
    auto newScene = levelOne.createScene();
    auto transition = TransitionFade::create(1.0f, newScene);
    Director::getInstance()->replaceScene(transition);

    std::cout << "menusscene callback end" << std::endl;
}

void MenuScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif


    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
