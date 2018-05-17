//
//  Method2OpenUrl.mm
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 17/05/2018.
//

#import <Foundation/Foundation.h>
#include "Method2OpenUrl.h"

void Method2OpenUrl::open(const std::string& url)
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding]]];
}
