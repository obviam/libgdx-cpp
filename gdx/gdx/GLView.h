//
//  GLView.h
//  gdx
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import "ApplicationInterface.h"

@interface GLView : UIView {
@private
    EAGLContext*                context;
    float                       timestamp;
    gdx::ApplicationInterface*  app;
}

- (id)initWithFrame:(CGRect)frame applicationListener:(gdx::ApplicationListenerInterface*)listener;
- (void) drawView: (CADisplayLink*)displayLink;

@end
