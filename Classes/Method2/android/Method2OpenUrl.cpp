//
//  Method2OpenUrl.cpp
//  Cocos2dxTutorial
//
//  Created by n2n on 21/05/2018.
//

#include "../Method2OpenUrl.h"
#include "platform/android/jni/JniHelper.h"

static const std::string helperClassName = "org/cocos2dx/cpp/AppActivity";

void Method2OpenUrl::open(const std::string& url)
{
    cocos2d::JniHelper::callStaticVoidMethod(helperClassName, "openUrl", url);
}

