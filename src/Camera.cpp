#include "Camera.h"

#include <iostream>

using namespace std;

Camera::Camera(SDL_Rect* newRect)
{
	mRect = new PosRect;

	mRect->x = newRect->x;
	mRect->y = newRect->y;
	mRect->w = newRect->w;
	mRect->h = newRect->h;

	speed = 0.005;
	maxSpeedFromDistance = 30.0;

	this->jump = false;
	this->slide = false;
	this->softSlide = false;

	canvasWidth = 5000;
	canvasHeight = 3000;
}

void Camera::executeOrder(CameraOrder order)
{
	if (order.jumpOrder){
		jumpPrepare(order);
	}
	else if (order.slideOrder){
		slidePrepare(order);
	}
	else if (order.softSlideOrder) {
		softSlidePrepare(order);
	}
	else if (order.resizeCanvasOrder){
		canvasWidth = order.canvasWidth;
		canvasHeight = order.canvasHeight;
	}
}

void Camera::jumpPrepare(CameraOrder order)
{
	this->targetX = order.x;
	this->targetY = order.y;

	if (this->targetX < 0)
		this->targetX = 0;
	if (this->targetX > canvasWidth)
		this->targetX = canvasWidth;
	if (this->targetY < 0)
		this->targetY = 0;
	if (this->targetY > canvasHeight)
		this->targetY = canvasHeight;

	this->jump = true;
}

void Camera::slidePrepare(CameraOrder order)
{

	this->targetX = order.x;
	this->targetY = order.y;

	if (this->targetX < 0)
		this->targetX = 0;
	if (this->targetX > canvasWidth)
		this->targetX = canvasWidth;
	if (this->targetY < 0)
		this->targetY = 0;
	if (this->targetY > canvasHeight)
		this->targetY = canvasHeight;

	this->slide = true;
}

void Camera::softSlidePrepare(CameraOrder order)
{

	this->targetX = order.x;
	this->targetY = order.y;

	if (this->targetX < 0)
		this->targetX = 0;
	if (this->targetX > canvasWidth)
		this->targetX = canvasWidth;
	if (this->targetY < 0)
		this->targetY = 0;
	if (this->targetY > canvasHeight)
		this->targetY = canvasHeight;

	this->softSlide = true;
}

void Camera::adjust(float time)
{
	if (jump)
	{
		doJump(time);
	}
	if (slide)
	{
		doSlide(time);
	}
	if (softSlide)
	{
		doSoftSlide(time);
	}
}

void Camera::doJump(float time)
{
	mRect->x = this->targetX;
	mRect->y = this->targetY;

	jump = false;
}

void Camera::doSlide(float time)
{
	float vectorX = targetX - mRect->x;
	float vectorY = targetY - mRect->y;

	float speedFromDistance = sqrt(vectorX * vectorX + vectorY * vectorY);

	recalculateVectors(vectorX, vectorY);

	mRect->x = mRect->x + vectorX * time * speed * maxSpeedFromDistance;
	mRect->y = mRect->y + vectorY * time * speed * maxSpeedFromDistance;

	if (mRect->x + 2 > targetX && mRect->x -2 < targetX && mRect->y + 2 > targetY && mRect->y -2 < targetY)
	{
		slide = false;
	}
}

void Camera::doSoftSlide(float time)
{
	float vectorX = targetX - mRect->x;
	float vectorY = targetY - mRect->y;

	float speedFromDistance = sqrt(vectorX * vectorX + vectorY * vectorY);

	recalculateVectors(vectorX, vectorY);

	if (speedFromDistance > maxSpeedFromDistance)
		speedFromDistance = maxSpeedFromDistance;


	mRect->x = mRect->x + vectorX * time * speed * speedFromDistance;
	mRect->y = mRect->y + vectorY * time * speed * speedFromDistance;

	if (mRect->x + 2 > targetX && mRect->x - 2 < targetX && mRect->y + 2 > targetY && mRect->y - 2 < targetY)
	{
		softSlide = false;
	}
}

void Camera::recalculateVectors(float &vectorX, float &vectorY)
{
	float absX;
	float absY;

	if (vectorX < 0.0)
		absX = -vectorX;
	else
		absX = vectorX;

	if (vectorY < 0.0)
		absY = -vectorY;
	else
		absY = vectorY;

	if (absX > absY) {
		vectorX = vectorX * (1.0 / absX);
		vectorY = vectorY * (1.0 / absX);
	}
	else {
		vectorY = vectorY * (1.0 / absY);
		vectorX = vectorX * (1.0 / absY);
	}
}