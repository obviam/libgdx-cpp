//
//  IOSGraphics.cpp
//  gdx
//
//  Created by Tamas Jano on 09/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GraphicsInterface.h"
#include "ApplicationInterface.h"

namespace gdx 
{
    
class IOSApplication;

class IOSGraphics : public GraphicsInterface
{
private:
    int     width;
	int     height;
	long    lastFrameTime;
	float   deltaTime;
	long    frameStart;
	int     frames;
	int     fps;
	float   ppiX;
	float   ppiY;
	float   ppcX;
	float   ppcY;
	float   density;
protected:
    IOSApplication* app;
public:
    bool const isGL11Available()
    {
        return true;
    };
    bool const isGL20Available()
    {
        return true;
    };
    
	int const getWidth()
    {
        return width;
    }
    
	int const getHeight()
    {
        return height;
    }
    
	float const getDeltaTime()
    {
        return deltaTime;
    }
    
	int const getFramesPerSecond()
    {
        return fps;
    }
    
	GraphicsType const getType()
    {
        return kIOSGL;
    };
    
	float const getPpiX()
    {
        return ppiX;
    };
    
	float const getPpiY()
    {
        return ppiY;
    };
    
	float const getPpcX()
    {
        return ppcX;
    };
    
	float getPpcY()
    {
        return ppcY;
    };
    
	float const getDensity()
    {
        return density;
    };
    
	bool const supportsDisplayModeChange()
    {
        return false;
    };
    
	DisplayMode** const getDisplayModes()
    {
        // TODO implement
        return NULL;
    }
    
	DisplayMode* const getDesktopDisplayMode()
    {
        // TODO implement
        return NULL;
    }
    
	bool setDisplayMode(gdx::DisplayMode *displayMode)
    {
        return false;
    }
    
	bool setDisplayMode (int width, int height, bool fullscreen)
    {
        return false;
    };
    
	void setTitle (char* title)
    {
        // nuffin'
    };
    
	void setVSync (bool vsync)
    {
        // nuffin'
    };
};
    
}