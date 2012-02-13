//
//  ScreenInterface.h
//  gdx
//
//  Created by Tamas Jano on 10/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_ScreenInterface_h
#define gdx_ScreenInterface_h

namespace gdx
{

/** <p>
 * Represents one of many application screens, such as a main menu, a settings menu, the game screen and so on.
 * </p>
 * <p>
 * Note that {@link #dispose()} is not called automatically.
 * </p>
 * @see Game */
class ScreenInterface {
public:
	/** Called when the screen should render itself.
	 * @param delta The time in seconds since the last render. */
	virtual void render (float delta) = 0;
    
	/** @see ApplicationListener#resize(int, int) */
	virtual void resize (int width, int height) = 0;
    
	/** Called when this screen becomes the current screen for a {@link Game}. */
	virtual void show () = 0;
    
	/** Called when this screen is no longer the current screen for a {@link Game}. */
	virtual void hide () = 0;
    
	/** @see ApplicationListener#pause() */
	virtual void pause () = 0;
    
	/** @see ApplicationListener#resume() */
	virtual void resume () = 0;
    
	/** Called when this screen should release all resources. */
	virtual void dispose () = 0;

    virtual ~ScreenInterface() {}
}
    
}
#endif
