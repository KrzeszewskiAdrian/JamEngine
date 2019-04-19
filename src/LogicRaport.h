#pragma once

#include "RenderOrderPack.h"
#include "CameraOrderPack.h"
#include "SoundOrderPack.h"

class LogicRaport
{
public:
	bool isGameFinished;

	float time;

	LogicRaport();

	//Overloaded methods to add any type of order
	void add(RenderOrder order);
	void add(CameraOrder order);
	void add(SoundOrder order);

private:
	//Lists of orders to execute
	RenderOrderPack mRenderOrderPack;
	CameraOrderPack mCameraOrderPack;	
	SoundOrderPack mSoundOrderPack;
public:
	void setTime(float newTime);

	RenderOrderPack getRenderOrderPack();
	CameraOrderPack getCameraOrderPack();
	SoundOrderPack getSoundOrderPack();
};