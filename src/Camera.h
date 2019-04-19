#pragma once

#include <SDL.h>

#include "PosRect.h"
#include "CameraOrder.h"

class Camera 
{
public:
	PosRect* mRect;
private:
	//Viewport's canvas' width
	int canvasWidth;
	//Viewport's canvas' height
	int canvasHeight;

	bool jump;
	bool slide;
	bool softSlide;

	float speed;
	float maxSpeedFromDistance;

	int targetX;
	int targetY;
public:
	Camera(SDL_Rect* newRect);

	void executeOrder(CameraOrder order);
	//Jump to target position
	void jumpPrepare(CameraOrder order);
	void slidePrepare(CameraOrder order);
	void softSlidePrepare(CameraOrder order);

	void adjust(float time);
	void doJump(float time);
	void doSlide(float time);
	void doSoftSlide(float time);
	//Scales vectors to <-1; 1> range
	void recalculateVectors(float &vectorX, float &vectorY);
};