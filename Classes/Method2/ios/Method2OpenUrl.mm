//
//  Method2OpenUrl.mm
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 17/05/2018.
//

#import <Foundation/Foundation.h>
#include "../Method2OpenUrl.h"
#include "../../Method1/Url.h"
#include "UrlNative.h"

void Method2OpenUrl::open(const std::string& url)
{
    // openUrlDirectly(url);
    
    // openUrlFromMethod1(url);
    
    openUrlNative(url);
}

void Method2OpenUrl::openUrlDirectly(const std::string& url)
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithCString:url.c_str()
                                                                                       encoding:NSUTF8StringEncoding]]];
}

void Method2OpenUrl::openUrlFromMethod1(const std::string& url)
{
    std::shared_ptr<Url> urlObj = std::make_shared<Url>();
    urlObj->open(url);
}

void Method2OpenUrl::openUrlNative(const std::string& url)
{
    [ UrlNative open:[ NSString stringWithCString:url.c_str()
                                         encoding:[NSString defaultCStringEncoding ] ] ];
}
