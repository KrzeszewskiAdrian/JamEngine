#include "ClickableObjectsList.h"

ClickableObjectsList::ClickableObjectsList()
{

}

void ClickableObjectsList::add(Clickable newObject)
{
	mList.push_back(newObject);
}

void ClickableObjectsList::addRenderOrders(LogicRaport *mRaport, float time)
{
	mRaport->setTime(time);

	for (auto &object : mList)
	{
		if(object.visable)
			mRaport->add(object.generateRenderOrder());
	}
}
