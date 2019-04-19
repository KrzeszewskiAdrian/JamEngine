#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <string>

using namespace std;

class Texture
{
public:
	SDL_Texture* mTexture = NULL;

private:
	int width;
	int height;
	float rotation;
	int alpha;
public:
	Texture();
	Texture(int width, int height, float rotation, int alpha);
	bool load(SDL_Renderer* mRenderer, string name);

	int getWidth() { return width; };
	int getHeight() { return height; };
	int getRotation() { return rotation; };
	int getAlpha() { return alpha; };

	void close();
};