#include "SoundEffect.h"
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

#include <string>
using namespace std;

SoundEffect::SoundEffect()
{

}

bool SoundEffect::load(string name)
{
	string str = "./Resources/Sounds/" + name + ".wav";
	const char * path = str.c_str();
	mEffect = Mix_LoadWAV(path);
	if (mEffect == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Failed to load sound effect",
			NULL);
		return false;
	}
	return true;
}

void SoundEffect::close()
{
	Mix_FreeChunk(mEffect);
	mEffect = NULL;
}
