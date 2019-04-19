#include "Animation.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include "ConstantDefined.h"

using namespace std;

Animation::Animation()
{
	baseSpeed = 1;
}

Animation::Animation(int width, int height, int numberOfClips)
{
	baseSpeed = 1;

	this->numberOfClips = numberOfClips;

	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->alpha = alpha;
}

bool Animation::load(SDL_Renderer* mRenderer, string name)
{

	SDL_Surface* tempSurface = NULL;
	string number;

	mTexture = new SDL_Texture*[numberOfClips];

	for (int i = 0; i < numberOfClips; i++)
	{
		tempSurface = IMG_Load(("./Resources/Animations/" + name + "/" + name + makeEnumeratingString(i) + ".png").c_str());
		SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, RcolorTransparent, GcolorTransparent, BcolorTransparent));
		mTexture[i] = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
		SDL_FreeSurface(tempSurface);
	}

	if (mTexture == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Loading aniamtion error",
			NULL);
		return false;
	}

	return true;
}

string Animation::makeEnumeratingString(int n)
{
	string number;
	if (n < 10)
		number = "0000";
	else if (n < 100)
		number = "000";
	else if (n < 1000)
		number = "00";
	else if (n < 10000)
		number = "0";
	else if (n < 100000)
		number = "";
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Animation to long!",
			NULL);
	}

	number = number + to_string(n);

	return number;
}

void Animation::updateOffset(float time, float speed, float* offset)
{
	*offset = *offset + (baseSpeed * speed * time);
	if (*offset >= numberOfClips)
	{
		*offset = *offset - (numberOfClips * ((int)*offset / numberOfClips));
	}
}


void Animation::close()
{
	for (int i = 0; i++; i < numberOfClips)
	{
		SDL_DestroyTexture(mTexture[i]);
		mTexture[i] = NULL;
	}
}
