//
//  ApplicationAdapter.cpp
//  gdx
//
//  Created by Tamas Jano on 13/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ApplicationListenerInterface.h"

namespace gdx
{
    
/** Convenience implementation of {@link ApplicationListener}. Derive from this and only override what you need. **/
class ApplicationAdapter : public ApplicationListenerInterface
{
public:
    ApplicationAdapter() {};
    void create() {};
    void resize(int width, int height) {};
    void render() {};
    void pause() {};
    void resume() {};
    void dispose() {};
    ~ApplicationAdapter() {
        dispose();
    }
};

class ApplicationListenerInterface* createApplicationAdapter()
{
    return new ApplicationAdapter();
}

}