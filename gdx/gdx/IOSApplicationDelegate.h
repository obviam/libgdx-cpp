//
//  IOSApplicationDelegate.h
//  gdx
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLView.h"
#import "IOSApplication.cpp"

@interface IOSApplicationDelegate : NSObject <UIApplicationDelegate> 
{
    UIWindow*               m_window;
    GLView*                 m_view;
    gdx::IOSApplication*    application;
}

@property (strong, nonatomic) UIWindow *m_window;

@end
