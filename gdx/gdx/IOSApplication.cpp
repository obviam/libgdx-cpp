//
//  IOSApplication.cpp
//  gdx
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ApplicationInterface.h"
#include "ApplicationListenerInterface.h"
#include "GraphicsInterface.h"

namespace gdx
{

class IOSApplicationConfiguration
{
public: 
    bool useGLES20;
    bool useAccelerometer;
    bool hideStatusBar;
};
    
class IOSApplication : public ApplicationInterface
{
 
private:
    const ApplicationListenerInterface* listener;
    
public:
    IOSApplication();
    void initialize(ApplicationListenerInterface* listener, IOSApplicationConfiguration* config);
    GraphicsInterface* getGraphics();
};

ApplicationInterface* createIOSApplication()
{
    return new IOSApplication();
}
    
// ~ implementations
IOSApplication::IOSApplication()
{
    printf("IOSApplication created\n");
};

void IOSApplication::initialize(ApplicationListenerInterface* listener, IOSApplicationConfiguration* config)
{
//    graphics = createIOSGraphics(640, 960);
};

GraphicsInterface* IOSApplication::getGraphics()
{
    return graphics;
};

}