//
//  RendererInterface.h
//  gdx
//
//  Created by Tamas Jano on 14/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_RendererInterface_h
#define gdx_RendererInterface_h

namespace gdx
{

class RendererInterface {
public:
    virtual void initialize(int width, int height) = 0;
    virtual void render() const = 0;
    virtual ~RendererInterface() {}
};

class RendererInterface* createSimpleRendererGL2();

}
#endif
