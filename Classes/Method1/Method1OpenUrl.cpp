//
//  Method1OpenUrl.cpp
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 16/05/2018.
//

#include "Method1OpenUrl.h"
#include "Url.h"

void Method1OpenUrl::open(const std::string& url)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // TODO: next tutorial on android part.
    
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::shared_ptr<Url> urlObj = std::make_shared<Url>();
    urlObj->open(url);
#endif
}
