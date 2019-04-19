#include <iostream>
#include "Viewport.h"

using namespace std;


Viewport::Viewport(SDL_Rect newRect)
{
	mRect = new SDL_Rect;

	mRect->x = newRect.x;
	mRect->y = newRect.y;
	mRect->w = newRect.w;
	mRect->h = newRect.h;

	mCamera = new Camera(mRect);
}

Viewport::Viewport(int x, int y, int width, int height)
{
	mRect = new SDL_Rect;

	mRect->x = x;
	mRect->y = y;
	mRect->w = width;
	mRect->h = height;

	mCamera = new Camera(mRect);
}
