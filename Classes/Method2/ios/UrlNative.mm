//
//  UrlNative.mm
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 17/05/2018.
//


#import "UrlNative.h"

@implementation UrlNative
+ (void) open:(NSString*) url
{
    [ [ UIApplication sharedApplication ] openURL:[ NSURL URLWithString:url ] ];
}
@end
