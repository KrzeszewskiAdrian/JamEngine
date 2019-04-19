#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Camera.h"

class Viewport
{
public:
	Viewport(SDL_Rect newRect);
	Viewport(int x, int y, int width, int height);
	SDL_Rect* mRect;
	Camera* mCamera = NULL;
private:
	//
public:
	int getX() { return mRect->x; };
	int getY() { return mRect->y; };
	int getWidth() { return mRect->w; };
	int getHeight() { return mRect->h; };
};