#include "SoundManager.h"

#include <map>
#include <typeinfo>
#include <SDL.h>
#include <SDL_mixer.h>

#include "Settings.h";
#include "SoundEffect.h"

#include "SoundOrderPack.h"

#include <algorithm>
#include <string>

using namespace std;

SoundManager::SoundManager()
{
	
}


int SoundManager::loading(InitSettings settings)
{
	for (const auto& name : settings.soundNamesList) {
		SoundEffect newSound;
		if (name != "" && !newSound.load(name)) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Couldn't load sound effect (is format correct?)",
				NULL);
			return -1;
		}
			
		effectVault[name] = newSound;
	}
	

	///temp solution
	return 100;
}

void SoundManager::playSounds(SoundOrderPack SoundOrderPack)
{
	
	///Sound orders:
	for (const auto& order : SoundOrderPack.ordersList) {
		play(order);
	}
}

bool SoundManager::play(SoundOrder order)
{
	itEffect = effectVault.find(order.getSoundName());
	if (itEffect != effectVault.end()){
		
		if (Mix_PlayChannel(-1, itEffect->second.mEffect, 0) == -1) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Sound couldn't be played.",
				NULL);
			return false;
		}

		return true;
	}
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Sound couldn't be found.",
			NULL);
		return false;
	}
}

void SoundManager::close()
{
	/*
	for (std::map<string, Sound>::iterator it = soundVault.begin(); it != soundVault.end(); ++it)
		it->second.close();
		*/

}