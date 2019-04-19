#include "RenderableObjectsList.h"

RenderableObjectsList::RenderableObjectsList(lc mLayer, vpc mViewport)
{
	this->mLayer = mLayer;
	this->mViewport = mViewport;
}

void RenderableObjectsList::add(Renderable newObject)
{
	mList.push_back(newObject);
}

void RenderableObjectsList::addRenderOrders(LogicRaport *mRaport, float time)
{
	mRaport->setTime(time);

	for (auto &object : mList)
	{
		if (object.visable)
			mRaport->add(object.generateRenderOrder());
	}
}

