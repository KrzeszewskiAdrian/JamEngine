#pragma once
#include <SDL.h>
#include <SDL_mixer.h>

#include <string>

using namespace std;

///SDL_Music cannot be used becouse of SDL2 library bug!
///Use Effect for every sound instead

class SoundEffect
{
public:
	SoundEffect();
	Mix_Chunk * mEffect = NULL;
private:
	//
public:
	bool load(string name);
	void close();
};