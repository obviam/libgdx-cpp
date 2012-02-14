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
        
        if (api == kEAGLRenderingAPIOpenGLES1) {
            NSLog(@"Using OpenGL ES 1.1");
//            renderingEngine = CreateRenderer1();
        } else {
            NSLog(@"Using OpenGL ES 2.0");
//            renderingEngine = CreateRenderer2();
        }
        
        [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
        
//        renderingEngine->Initialize(CGRectGetWidth(frame), CGRectGetHeight(frame));
        
        appListener->create();
        appListener->resize(CGRectGetWidth(frame), CGRectGetHeight(frame));
        
        [self drawView:nil];
        
        timestamp = CACurrentMediaTime();
        
        CADisplayLink* displayLink;
        displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView:)];
        
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        
        [[NSNotificationCenter defaultCenter] 
         addObserver:self 
         selector:@selector(didRotate:) 
         name:UIDeviceOrientationDidChangeNotification 
         object:nil];
        
        
        //        GLuint framebuffer, renderbuffer;
        //        glGenFramebuffersOES(1, &framebuffer);
        //        glGenRenderbuffersOES(1, &renderbuffer);
        //        
        //        glBindFramebufferOES(GL_FRAMEBUFFER_OES, framebuffer);
        //        glBindRenderbufferOES(GL_RENDERBUFFER_OES, renderbuffer);
        //        
        //        [m_context 
        //            renderbufferStorage:GL_RENDERBUFFER_OES 
        //            fromDrawable:eaglLayer];
        //        
        //        glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, renderbuffer);
        //        
        //        glViewport(0, 0, CGRectGetWidth(frame), CGRectGetWidth(frame));
        //        
        //        [self drawView];
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
