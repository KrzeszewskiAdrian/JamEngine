#pragma once

#include <string>

#include "PosRect.h"

using namespace std;

//Class to manage animations joined with their sounds
class QuickAnimation
{
public:
	bool isActive;

	string animationName;
	string soundName;

	PosRect mRect;

	float speed;
	
	///Set to wanted number of frame to play animation from this frame
	///Will be increades once per frame, to "scroll" animation forward
	float offset;
	//Time from beginning of sound to beginning of animation; May have negative value, to play animation first. [ms]
	float animationDelay;

	QuickAnimation(string animationName, string soundName, PosRect mRect, float speed, float animationDelay);
};