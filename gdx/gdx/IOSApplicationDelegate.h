//
//  IOSApplicationDelegate.h
//  gdx
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLView.h"

@interface IOSApplicationDelegate : NSObject <UIApplicationDelegate> 
{
    UIWindow*   window;
    GLView*     view;
}

@property (strong, nonatomic) UIWindow *window;

@end
