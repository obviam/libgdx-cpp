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
    
class IOSApplication : public ApplicationInterface
{
 
private:
    const ApplicationListenerInterface* listener;
    
public:
    IOSApplication();
    void initialize(ApplicationListenerInterface* listener, ApplicationConfiguration* config);
    GraphicsInterface* getGraphics();
};

ApplicationInterface* createIOSApplication(ApplicationListenerInterface* listener, ApplicationConfiguration* config)
{
    IOSApplication* app = new IOSApplication();
    app->initialize(listener, config);
    return app;
}
    
// ~ implementations
IOSApplication::IOSApplication()
{
    printf("IOSApplication created\n");
};

void IOSApplication::initialize(ApplicationListenerInterface* listener, ApplicationConfiguration* config)
{
    graphics = createIOSGraphics(640, 960);
};

GraphicsInterface* IOSApplication::getGraphics()
{
    return graphics;
};

}