/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Method1/Method1OpenUrl.h"
#include "Method2/Method2OpenUrl.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to open a browser for method 1.

    auto menuItem1 = createMenuItem(origin + Vec2(visibleSize.width * 0.3f,
                                                  visibleSize.height * 0.5f));
    
    menuItem1->setCallback(CC_CALLBACK_1(HelloWorld::menuOpenMethod1, this));
    
    /////////////////////////////
    // 3. add a menu item with "X" image, which is clicked to open a browser for method 2.
    
    auto menuItem2 = createMenuItem(origin + Vec2(visibleSize.width * 0.7f,
                                                  visibleSize.height * 0.5f));
    
    menuItem2->setCallback(CC_CALLBACK_1(HelloWorld::menuOpenMethod2, this));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 4. add a label shows Method 1
    
    auto label = createLabel("Method 1",
                             Vec2(origin.x + visibleSize.width * 0.3f,
                                  origin.y + visibleSize.height * 0.5f - 50));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    /////////////////////////////
    // 5. add a label shows Method 2
    
    auto label2 = createLabel("Method 2",
                             Vec2(origin.x + visibleSize.width * 0.7f,
                                  origin.y + visibleSize.height * 0.5f - 50));
    
    // add the label as a child to this layer
    this->addChild(label2, 1);
    
    return true;
}

cocos2d::MenuItemImage* HelloWorld::createMenuItem(const cocos2d::Vec2& position)
{
    MenuItemImage* menuItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png");
    
    if (menuItem == nullptr ||
        menuItem->getContentSize().width <= 0 ||
        menuItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        menuItem->setPosition(position);
        menuItem->setScale(2.5f);
    }
    
    return menuItem;
}

cocos2d::Label* HelloWorld::createLabel(const std::string& title, const cocos2d::Vec2& position)
{
    Label* label = Label::createWithTTF(title, "fonts/Marker Felt.ttf", 15);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(position);
    }
    
    return label;
}


void HelloWorld::menuOpenMethod1(Ref* pSender)
{
    // Call the open url method 1
    Method1OpenUrl::open("http://www.werakugames.com");
}

void HelloWorld::menuOpenMethod2(cocos2d::Ref* pSender)
{
    // Call the open url method 2
    Method2OpenUrl::open("http://www.superstickbadminton.com");
}
