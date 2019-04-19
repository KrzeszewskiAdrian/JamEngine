#include "QuickAnimation.h"

QuickAnimation::QuickAnimation(string animationName, string soundName, PosRect mRect, float speed, float animationDelay)
{
	this->animationName = animationName;
	this->soundName = soundName;
	this->mRect = mRect;
	this->speed = speed;
	this->animationDelay = animationDelay;

	isActive = true;
	offset = 0.0;
}