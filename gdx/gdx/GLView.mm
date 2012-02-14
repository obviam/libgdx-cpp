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

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
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

void drawView (void * glViewInstance, float elapsed) {
    
}


- (void) drawView: (CADisplayLink*) displayLink
{
    if (displayLink != nil) {
//        float elapsedSeconds = displayLink.timestamp - timestamp;
//        timestamp = displayLink.timestamp;
    }
    
    // rendering needs to come here
    
    [context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)dealloc
{
    if ([EAGLContext currentContext] == context)
        [EAGLContext setCurrentContext:nil];
    
    [context release];
    
    [super dealloc];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
