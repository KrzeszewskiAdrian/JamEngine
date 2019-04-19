#include "LogicRaport.h"

using namespace std;

LogicRaport::LogicRaport()
{
	isGameFinished = false;
}

void LogicRaport::add(RenderOrder order)
{
	mRenderOrderPack.put(order);
}

void LogicRaport::add(CameraOrder order)
{
	mCameraOrderPack.put(order);
}

void LogicRaport::add(SoundOrder order)
{
	mSoundOrderPack.put(order);
}

RenderOrderPack LogicRaport::getRenderOrderPack()
{
	return mRenderOrderPack;
}

CameraOrderPack LogicRaport::getCameraOrderPack()
{
	return mCameraOrderPack;
}

SoundOrderPack LogicRaport::getSoundOrderPack()
{
	return mSoundOrderPack;
}

void LogicRaport::setTime(float newTime)
{
	this->time = newTime;
	mRenderOrderPack.setTime(newTime);
}

