//
//  Graphics.h
//  gdx
//
//  Created by Tamas Jano on 08/02/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef gdx_GraphicsInterface_h
#define gdx_GraphicsInterface_h

namespace gdx 
{

enum GraphicsType {
    kIOSGL, kDesktopGL
};

struct DisplayMode
{
    const int width;
    const int height;
    const int refreshRate;
    const int bitsPerPixel;
        
    DisplayMode(int _width, int _height, int _refreshRate, int _bitsPerPixel):
        width(_width),
        height(_height),
        refreshRate(_refreshRate),
        bitsPerPixel(_bitsPerPixel) {}
};

struct GraphicsInterface
{
    virtual bool const isGL11Available() = 0;
    virtual bool const isGL20Available() = 0;

	/** @return the width in pixels of the display surface */
	virtual int const getWidth() = 0;
    
	/** @return the height in pixels of the display surface */
	virtual int const getHeight() = 0;
    
	/** @return the time span between the current frame and the last frame in seconds */
	virtual float const getDeltaTime() = 0;
    
	/** @return the average number of frames per second */
	virtual int const getFramesPerSecond() = 0;
    
	/** @return the {@link GraphicsType} of this Graphics instance */
	virtual GraphicsType const getType() = 0;
    
	/** @return the pixels per inch on the x-axis */
	virtual float const getPpiX() = 0;
    
	/** @return the pixels per inch on the y-axis */
	virtual float const getPpiY() = 0;
    
	/** @return the pixels per centimeter on the x-axis */
	virtual float const getPpcX() = 0;
    
	/** @return the pixels per centimeter on the y-axis. */
	virtual float getPpcY() = 0;
    
	/** This is a scaling factor for the Density Independent Pixel unit, following the same conventions as
	 * android.util.DisplayMetrics#density, where one DIP is one pixel on an approximately 160 dpi screen. Thus on a 160dpi screen
	 * this density value will be 1; on a 120 dpi screen it would be .75; etc.
	 * 
	 * @return the logical density of the Display. */
	virtual float const getDensity() = 0;
    
	/** Whether the given backend supports a display mode change via calling {@link Graphics#setDisplayMode(DisplayMode)}
	 * @return whether display mode changes are supported or not. */
	virtual bool const supportsDisplayModeChange() = 0;
    
	/** @return the supported fullscreen {@link DisplayMode}. */
	virtual DisplayMode** const getDisplayModes() = 0;
    
	/** @return the display mode of the primary graphics adapter. */
	virtual DisplayMode* const getDesktopDisplayMode() = 0;
    
	/** Sets the current {@link DisplayMode}. Returns false in case the operation failed. Not all backends support this methods. See
	 * {@link Graphics#supportsDisplayModeChange()}.
	 * 
	 * @param displayMode the display mode.
	 * @return whether the operation succeeded. */
	virtual bool setDisplayMode(gdx::DisplayMode *displayMode) = 0;
    
	/** Tries to set the display mode width the given width and height in pixels. Will always succeed if fullscreen is set to false,
	 * in which case the application will be run in windowed mode. Use {@link Graphics#getDisplayModes()} to get a list of
	 * supported fullscreen modes.
	 * 
	 * @param width the width in pixels
	 * @param height the height in pixels
	 * @param fullscreen whether to use fullscreen rendering or not */
	virtual bool setDisplayMode (int width, int height, bool fullscreen) = 0;
    
	/** Sets the title of the window. Ignored on Android.
     * @param title the title. */
	virtual void setTitle (char* title) = 0;
    
	/** Sets one or more icons for the Desktop. This only works for Lwjgl. On Windows you should supply at least one 16x16 icon and
	 * one 32x32. Linux (and similar platforms) expect one 32x32 icon. Mac OS X should be supplied one 128x128 icon
	 * @param pixmaps 1 or more Pixmaps using {@link Format#RGBA8888} */
//	virtual void setIcon(Pixmap[] pixmaps);
    
	/** Enable/Disable vsynching. This is a best-effort attempt which might not work on all platforms.
	 * @param vsync vsync enabled or not. */
	virtual void setVSync (bool vsync) = 0;
    
	/** @return the format of the color, depth and stencil buffer in a {@link BufferFormat} instance */
//	virtual BufferFormat getBufferFormat() = 0;
    
	/** @param extension the extension name
	 * @return whether the extension is supported */
//	virtual bool supportsExtension (String extension) = 0;
};


}
#endif
