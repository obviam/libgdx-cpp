//
//  InputProcessorInterface.h
//  gdx
//
//  Created by Tamas Jano on 10/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_InputProcessorInterface_h
#define gdx_InputProcessorInterface_h

namespace gdx 
{

/** An InputProcessor is used to receive input events from the keyboard and the touch screen (mouse on the desktop). For this it
 * has to be registered with the {@link Input#setInputProcessor(InputProcessor)} method. It will be called each frame before the
 * call to {@link ApplicationListener#render()}. The methods return a* bool in case you want to write a multiplexing
 * InputProcessor that has a chain of child processors that signal whether they processed the event. The {@link InputMultiplexer}
 * offers you exactly this functionality.
 * 
 * @author badlogicgames@gmail.com */
class InputProcessorInterface
{

public:
	/** Called when a key was pressed
	 * 
	 * @param keycode one of the constants in {@link Input.Keys}
	 * @return whether the input was processed */
	virtual bool keyDown (int keycode) = 0;
    
	/** Called when a key was released
	 * 
	 * @param keycode one of the constants in {@link Input.Keys}
	 * @return whether the input was processed */
	virtual bool keyUp (int keycode) = 0;
    
	/** Called when a key was typed
	 * 
	 * @param character The character
	 * @return whether the input was processed */
	virtual bool keyTyped (char character) = 0;
    
	/** Called when the screen was touched or a mouse button was pressed. The button parameter will be {@link Buttons#LEFT} on
	 * Android.
	 * 
	 * @param x The x coordinate, origin is in the upper left corner
	 * @param y The y coordinate, origin is in the upper left corner
	 * @param pointer the pointer for the event.
	 * @param button the button
	 * @return whether the input was processed */
	virtual bool touchDown (int x, int y, int pointer, int button) = 0;
    
	/** Called when a finger was lifted or a mouse button was released. The button parameter will be {@link Buttons#LEFT} on
	 * Android.
	 * 
	 * @param x The x coordinate
	 * @param y The y coordinate
	 * @param pointer the pointer for the event.
	 * @param button the button
	 * @return whether the input was processed */
	virtual bool touchUp (int x, int y, int pointer, int button) = 0;
    
	/** Called when a finger or the mouse was dragged.
	 * 
	 * @param x The x coordinate
	 * @param y The y coordinate
	 * @param pointer the pointer for the event.
	 * @return whether the input was processed */
	virtual bool touchDragged (int x, int y, int pointer) = 0;
    
	/** Called when the mouse was moved without any buttons being pressed. Will not be called on Android.
	 * 
	 * @param x The x coordinate
	 * @param y The y coordinate
	 * @return whether the input was processed */
	virtual bool touchMoved (int x, int y) = 0;
    
	/** Called when the mouse wheel was scrolled. Will not be called on Android.
	 * @param amount the scroll amount, -1 or 1 depending on the direction the wheel was scrolled.
	 * @return whether the input was processed. */
	virtual bool scrolled (int amount) = 0;
    
    virtual ~InputProcessorInterface() {};
}

}

#endif
