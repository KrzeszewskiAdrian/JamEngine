#pragma once

#include "ViewportCode.h"

class CameraOrder
{
public:
	CameraOrder(vpc viewportCode);
	vpc viewportCode;
	bool resizeCanvasOrder;
	bool jumpOrder;
	bool slideOrder;
	bool softSlideOrder;

	int canvasWidth;
	int canvasHeight;

	int x;
	int y;

	//Set resize order
	void resizeLevel(int canvasWidth, int canvasHeight);
	//Set jump order
	void jump(int x, int y);
	void slide(int x, int y);
	void softSlide(int x, int y);
};