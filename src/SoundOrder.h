#pragma once

#include "Texture.h"
#include "ViewportCode.h"

class SoundOrder
{
public:
	SoundOrder(string soundName);
private:
	string soundName;
	int channel;
	
public:
	string getSoundName() { return soundName; };
};