//
//  Application.h
//  gdx-ios
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_Application_h
#define gdx_Application_h

#include "GraphicsInterface.h"
#include "ApplicationListenerInterface.h"

namespace gdx
{

class GraphicsInterface;

enum ApplicationType {
    kDesktop,
    kIOS,
    kAndroid
};

class ApplicationConfiguration
{
public: 
    bool useGLES20;
    bool useAccelerometer;
    bool hideStatusBar;
    // TODO - extend with what can be configured
};

class ApplicationInterface* createIOSApplication(ApplicationListenerInterface* listener, ApplicationConfiguration* config);
    
class ApplicationInterface
{
public:
    virtual GraphicsInterface* getGraphics() = 0;
    virtual ~ApplicationInterface() {}
    
protected:
    GraphicsInterface* graphics;
};

}

#endif
