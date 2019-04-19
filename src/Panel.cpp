#include "Panel.h"

#include <iostream>
#include <cmath>

using namespace std;

Panel::Panel()
{
	maxSpeed = 1.0;
	speed = 1.0;
}

Panel::Panel(vpc viewportCode, SDL_Rect* panelRect)
{
	this->mViewport = viewportCode;

	this->panelRect = new SDL_Rect{ panelRect->x , panelRect->y, panelRect->w, panelRect->h };
	this->cameraRect = new SDL_Rect{ 0, 0, panelRect->w, panelRect->h };

	maxSpeed = 1.0;
	speed = 0.005;
}


Panel::Panel(vpc viewportCode, SDL_Rect* panelRect, SDL_Rect* cameraRect)
{
	this->mViewport = viewportCode;

	this->panelRect = new SDL_Rect{ panelRect->x , panelRect->y, panelRect->w, panelRect->h };
	this->cameraRect = new SDL_Rect{ cameraRect->x , cameraRect->y, cameraRect->w, cameraRect->h };

	maxSpeed = 1.0;
	speed = 0.005;
}

void Panel::setTargetCenter(int targetX, int targetY)
{
	this->targetX = targetX - (cameraRect->w / 2);
	this->targetY = targetY - (cameraRect->h / 2);
}

void Panel::setTargetTopLeft(int targetX, int targetY)
{
	this->targetX = targetX;
	this->targetY = targetY;
}

void Panel::move(float time)
{
	float vectorX = (targetX - cameraRect->x) * speed * time;
	float vectorY = (targetY - cameraRect->y) * speed * time;

	if ((abs(vectorX) > maxSpeed * time) || (abs(vectorY) > maxSpeed * time))
	{
		if (abs(vectorX) >= abs(vectorY))
		{
			vectorY = abs((maxSpeed * time) / vectorX) * vectorY;
			if (vectorX >= 0)
				vectorX = maxSpeed * time;
			else
				vectorX = maxSpeed * time * -1;
		}
		else
		{
			vectorX = abs((maxSpeed * time) / vectorY) * vectorX;
			if (vectorY >= 0)
				vectorY = maxSpeed * time;
			else
				vectorY = maxSpeed * time * -1;
		}
	}

	cameraRect->x = cameraRect->x + vectorX;
	cameraRect->y = cameraRect->y + vectorY;
}

void Panel::stop()
{
	targetX = cameraRect->x;
	targetY = cameraRect->y;
}

bool Panel::checkIfIn(int x, int y)
{
	if (panelRect->x<x && panelRect->x + panelRect->w > x && panelRect->y<y && panelRect->y + panelRect->h > y)
	{
		return true;
	}
	return false;
}