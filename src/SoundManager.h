#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <map>

#include "SoundEffect.h"
#include "SoundOrderPack.h"
#include "InitSettings.h"
#include "Settings.h"

///SDL_Music cannot be used becouse of SDL2 library bug!
///Use Effect for every sound instead

class SoundManager
{
private:
	map<std::string, SoundEffect> effectVault;
	map<std::string, SoundEffect>::iterator itEffect;
public:
	SoundManager();
	int loading(InitSettings settings);
	void playSounds(SoundOrderPack OrderPack);
	bool play(SoundOrder order);
private:
	void close();
};