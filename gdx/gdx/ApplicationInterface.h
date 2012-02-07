//
//  Application.h
//  gdx-ios
//
//  Created by Tamas Jano on 07/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_Application_h
#define gdx_Application_h

namespace Gdx
{
    class ApplicationInterface
    {
      public:
        enum ApplicationType {
            Desktop, 
            iOS,
            Android
        };
        
        virtual ~ApplicationInterface() {}
    };
}

#endif
