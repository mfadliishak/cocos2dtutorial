//
//  Method2OpenUrl.h
//  Cocos2dxTutorial-mobile
//
//  Created by n2n on 17/05/2018.
//

#ifndef Method2OpenUrl_h
#define Method2OpenUrl_h

#include <string>

class Method2OpenUrl {
public:
    static void open(const std::string& url);
    
private:
    static void openUrlFromMethod1(const std::string& url);
    
    static void openUrlNative(const std::string& url);
    
    static void openUrlDirectly(const std::string& url);
};

#endif /* Method2OpenUrl_h */
