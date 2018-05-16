//
//  Url.mm
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 16/05/2018.
//

#import "Url.h"
#import <Foundation/Foundation.h>

Url::Url()
{
}

void Url::open(const std::string& url)
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding]]];
}
