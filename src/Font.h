#pragma once

#include <SDL.h>

#include <SDL_image.h>

#include <string>

using namespace std;

class Font
{
public:
	Font();

	//Font's bitmap
	SDL_Texture* mTexture;
	SDL_Rect mChars[256];
private:
	//Size of space
	double mSpace;
	//Size (vertical offset) of new line
	double mNewLine;

	void* mPixels;
	int mPitch;

	//Bitmap's width
	double mWidth;
	//Bitmap's height
	double mHeight;
	
	bool lockTexture();
	bool unlockTexture();
	Uint32 getPixel32(unsigned int x, unsigned int y);
	//Building font
	bool build();

public:
	bool load(SDL_Renderer* mRenderer, string name);

	int getSpace() { return mSpace; };
	int getNewLine() { return mNewLine; };
};