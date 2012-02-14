//
//  ApplicationAdapter.h
//  gdx
//
//  Created by Tamas Jano on 14/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_ApplicationAdapter_h
#define gdx_ApplicationAdapter_h

#include "ApplicationListenerInterface.h"

namespace gdx
{

class ApplicationAdapter : public ApplicationListenerInterface
{
public:
    ApplicationAdapter();
    void create();
    void resize(int width, int height);
    void render();
    void pause();
    void resume();
    void dispose();
    ~ApplicationAdapter();
};

class ApplicationListenerInterface* createApplicationAdapter();

}
#endif
