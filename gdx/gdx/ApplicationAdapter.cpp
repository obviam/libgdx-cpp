//
//  ApplicationAdapter.cpp
//  gdx
//
//  Created by Tamas Jano on 13/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ApplicationInterface.h"

namespace gdx
{

/** Convenience implementation of {@link ApplicationListener}. Derive from this and only override what you need. **/
class ApplicationAdapter : ApplicationInterface
{
public:
    void create() {};
    void resize(int width, int height) {};
    void render() {};
    void pause() {};
    void resume() {};
    void dispose() {};
};

}