#include "Texture.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include <string>
using namespace std;

Texture::Texture()
{

}

Texture::Texture(int width, int height, float rotation, int alpha)
{
	this->width = width;
	this->height = height;
	this->rotation = rotation;
	this->alpha = alpha;
}

bool Texture::load(SDL_Renderer* mRenderer, string name)
{

	SDL_Surface* tempSurface = IMG_Load(("./Resources/Textures/" + name + ".png").c_str());
	mTexture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);

	SDL_FreeSurface(tempSurface);

	if (mTexture == NULL)

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Texture not loaded correctly error ",
			NULL);

	return true;
}

void Texture::close()
{
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
}
