#include "AnimationSettings.h"
#include <iostream>

#include <string>

AnimationSettings::AnimationSettings(string name, int numberOfClips, int width, int height)
{
	this->name = name;
	this->numberOfClips = numberOfClips;
	this->width = width;
	this->height = height;
}