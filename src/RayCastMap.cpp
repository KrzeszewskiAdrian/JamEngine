#include "RayCastMap.h"

RayCastMap::RayCastMap()
{
	mWidth = 3840;
	mHeight = 2160;

	mRect = { 0, 0, 1920, 1080 };
}

bool RayCastMap::setUp(SDL_Renderer* mRenderer)
{
	string pathName = "./Resources/RayCastMap/main_background_detector.png";
	SDL_Surface* tempSurface = IMG_Load(pathName.c_str());
	if (tempSurface == NULL)
	{
		printf("Unable to load font: ", pathName.c_str(), IMG_GetError());
	}

	SDL_Texture* newTexture = NULL;

	formattedSurface = SDL_ConvertSurfaceFormat(tempSurface, SDL_PIXELFORMAT_RGBA8888, NULL);
	if (formattedSurface == NULL)
	{
		printf("Unable to convert loaded surface to display format! %s\n", SDL_GetError());
	}

	newTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h);
	if (newTexture == NULL)
	{
		printf("Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
	}

	SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);

	//Lock texture for manipulation
	SDL_LockTexture(newTexture, &formattedSurface->clip_rect, &mPixels, &mPitch);

	//Copy loaded/formatted surface pixels
	memcpy(mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);

	return true;
}

int RayCastMap::getColorCode(double x, double y)
{
	double calculatedX = ((x - mRect.x) + mRect.x) / mRect.w;
	double calculatedY = ((y - mRect.y) + mRect.y) / mRect.h;

	return (int)getPixelR(mWidth * calculatedX, mHeight * calculatedY);
}

bool RayCastMap::lockTexture()
{
	if (mPixels != NULL)
	{
		printf("Texture is already locked!\n");
	}
	else
	{
		if (SDL_LockTexture(mTexture, NULL, &mPixels, &mPitch) != 0)
		{
			printf("Unable to lock texture! %s\n", SDL_GetError());
			return false;
		}
	}
	return true;
}

bool RayCastMap::unlockTexture()
{
	if (mPixels == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,
			"JamEngine error",
			"Attempt to unlock locked texture. Skipped.",
			NULL);
		return true;
	}
	else
	{
		SDL_UnlockTexture(mTexture);
		mPixels = NULL;
		mPitch = 0;
	}

	return true;
}

Uint8 RayCastMap::getPixelR(unsigned int x, unsigned int y)
{
	//Convert the pixels to 32 bit
	Uint32 *pixels = (Uint32*)mPixels;

	Uint8* r = new Uint8();
	Uint8* g = new Uint8();
	Uint8* b = new Uint8();

	SDL_GetRGB(pixels[(y * (mPitch / 4)) + x], formattedSurface->format, r, g, b);

	return *r;
}