#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <string>

using namespace std;

class Animation
{
public:
	//Multiple frames holder
	SDL_Texture ** mTexture;
private:

	int width;
	int height;
	float rotation;
	int alpha;

	int numberOfClips;
	float baseSpeed;
public:
	Animation();
	Animation(int width, int height, int numberOfClips);
	bool load(SDL_Renderer* mRenderer, string name);
	string makeEnumeratingString(int n);

	//Updates offset of animation frame, to determine current frame
	void updateOffset(float time, float speed, float* offset);

	int getWidth() { return width; };
	int getHeight() { return height; };
	int getRotation() { return rotation; };
	int getAlpha() { return alpha; };

	void close();
};