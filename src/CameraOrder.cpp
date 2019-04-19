#include "CameraOrder.h"

CameraOrder::CameraOrder(vpc viewportCode)
{
	this->viewportCode = viewportCode;

	resizeCanvasOrder = false;
	jumpOrder = false;
	slideOrder = false;
	softSlideOrder = false;
}

void CameraOrder::resizeLevel(int canvasWidth, int canvasHeight)
{
	this->viewportCode = viewportCode;

	this->canvasWidth = canvasWidth;
	this->canvasHeight = canvasHeight;

	resizeCanvasOrder = true;
}

void CameraOrder::jump(int x, int y)
{
	this->viewportCode = viewportCode;

	this->x = x;
	this->y = y;
	jumpOrder = true;
}

void CameraOrder::slide(int x, int y)
{
	this->viewportCode = viewportCode;

	this->x = x;
	this->y = y;
	slideOrder = true;
}

void CameraOrder::softSlide(int x, int y)
{
	this->viewportCode = viewportCode;

	this->x = x;
	this->y = y;
	softSlideOrder = true;
}