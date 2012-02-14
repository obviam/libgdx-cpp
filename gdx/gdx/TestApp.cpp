//
//  TestApp.cpp
//  gdx
//
//  Created by Tamas Jano on 14/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ApplicationAdapter.h"
#include "RendererInterface.h"

class TestApp : public gdx::ApplicationAdapter
{
public:
    void create();
    void render();
    TestApp();
private:
    gdx::RendererInterface* renderer;
};

TestApp::TestApp()
{
    
}

void TestApp::create()
{
    renderer = gdx::createSimpleRendererGL2();
};

void TestApp::render()
{
    renderer->render();
}