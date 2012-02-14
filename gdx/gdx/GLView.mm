//
//  GLView.m
//  gdx
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "GLView.h"
#import <OpengLES/EAGLDrawable.h>
#import "mach/mach_time.h"
#import <OpenGLES/ES2/gl.h>

@implementation GLView

const bool forceES1 = false;
gdx::ApplicationListenerInterface* appListener;

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame applicationListener:(gdx::ApplicationListenerInterface*)listener
{
    gdx::ApplicationConfiguration *config = new gdx::ApplicationConfiguration();
    config->useGLES20 = true;
    appListener = listener;
    
    self->app = gdx::createIOSApplication(listener, config);
    
    if ((self = [super initWithFrame:frame])) {
        CAEAGLLayer* eaglLayer = (CAEAGLLayer*) super.layer;
        eaglLayer.opaque = YES;
        
        EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
        context = [[EAGLContext alloc] initWithAPI:api];
        
        if (!context || forceES1) {
            api = kEAGLRenderingAPIOpenGLES1;
            context = [[EAGLContext alloc] initWithAPI:api];
        }
        
        if (!context || ![EAGLContext setCurrentContext:context]) {
            [self release];
            return nil;
        }
        
        // Context has been created...it should be good to go from here
        
        appListener->create();
        appListener->resize(CGRectGetWidth(frame), CGRectGetHeight(frame));

        [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
        
        [self drawView:nil];
        
        timestamp = CACurrentMediaTime();
        
        CADisplayLink* displayLink;
        displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView:)];
        
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];

/*
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        
        [[NSNotificationCenter defaultCenter] 
         addObserver:self 
         selector:@selector(didRotate:) 
         name:UIDeviceOrientationDidChangeNotification 
         object:nil];
 */
        
    }
    return self;

}

- (void) drawView: (CADisplayLink*) displayLink
{
    if (displayLink != nil) {
        // TODO - need to do something with this to inject it into the Graphics instance
        float elapsedSeconds = displayLink.timestamp - timestamp;
        timestamp = displayLink.timestamp;
    }

    // delegating rendering to the application listener
    appListener->render();
    
    [context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void) pause
{
    if (appListener) {
        appListener->pause();
    }
}

- (void) resume
{
    if (appListener) {
        appListener->resume();
    }
}

- (void)dealloc
{
    appListener->dispose();
    
    if ([EAGLContext currentContext] == context)
        [EAGLContext setCurrentContext:nil];
    
    [context release];
    
    [super dealloc];
}


@end
