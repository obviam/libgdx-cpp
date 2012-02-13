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
#include "IOSGraphics.cpp"

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
};

// ~ implementations
IOSApplication::IOSApplication()
{
};

void IOSApplication::initialize(ApplicationListenerInterface* listener, IOSApplicationConfiguration* config)
{
    graphics = new IOSGraphics();
};

}