#pragma once

#include <SDL.h>

#include "ViewportCode.h"

//Logic equivalent of Viewport
class Panel
{
public:
	
private:
	///One Panel is connected to one Viewport
	vpc mViewport;

	SDL_Rect* panelRect;
	SDL_Rect* cameraRect;

	//Speed of camera
	float speed;
	float maxSpeed;

	//Target top left coordinates:
	int targetX;
	int targetY;

	bool isLocked = false;
public:
	Panel();
	//Constructor for camera equal to Panel
	Panel(vpc viewportCode, SDL_Rect* panelRect);
	//Constructor for camera smaller than Panel
	Panel(vpc viewportCode, SDL_Rect* panelRect, SDL_Rect* cameraRect);

	//Centering camera to specific location
	void setTargetCenter(int targetX, int targetY);
	//Centering camera to specific location
	void setTargetTopLeft(int targetX, int targetY);

	void move(float time);
	void lock() { isLocked = true; }
	void unlock() { isLocked = false; }
	void stop();

	//Testing position of point with Panel; Used to search for clicked/hovered objects faster
	bool checkIfIn(int x, int y);

	SDL_Rect* getPanelRect() { return panelRect; };
	SDL_Rect* getCameraRect() { return cameraRect; };
	vpc getCameraViewport() { return mViewport; };
	int getTargetX() { return targetX; };
	int getTargetY() { return targetY; };
	int getCameraX() { return cameraRect->x; };
	int getCameraY() { return cameraRect->y; };
};