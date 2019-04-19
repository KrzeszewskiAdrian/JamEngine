#pragma once

#include <iostream>

#include <SDL_image.h>

#include <string>

using namespace std;

///Class to create special hitboxes, clickboxes or hidden areas of detection;
///Stores png with mask, returns value of color at tested point
///May be used with camera system, viewport system etc.
//Hidden mask for special detection
class RayCastMap
{
public:
	RayCastMap();
	bool setUp(SDL_Renderer* mRenderer);

	//Returns R value of RGB format
	int getColorCode(double x, double y);

private:
	SDL_Texture* mTexture;
	void* mPixels;
	int mPitch;
	SDL_Rect mRect;

	//Image width
	double mWidth;
	//Image height
	double mHeight;

	bool lockTexture();
	bool unlockTexture();
	Uint8 getPixelR(unsigned int x, unsigned int y);

	SDL_Surface* formattedSurface;
};