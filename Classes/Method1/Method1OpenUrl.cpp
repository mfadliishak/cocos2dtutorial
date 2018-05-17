//
//  Method1OpenUrl.cpp
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 16/05/2018.
//

#include "Method1OpenUrl.h"
#include "Url.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"

static const std::string helperClassName = "org/cocos2dx/cpp/AppActivity";
#endif

void Method1OpenUrl::open(const std::string& url)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    cocos2d::JniHelper::callStaticVoidMethod(helperClassName, "openUrl", url);
    
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::shared_ptr<Url> urlObj = std::make_shared<Url>();
    urlObj->open(url);
#endif
}
