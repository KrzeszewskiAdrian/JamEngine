#include "RenderableLists.h"

void RenderableLists::add(RenderableObjectsList* newList)
{
	mList.push_back(newList);
}

void RenderableLists::renderAllLists(LogicRaport *mRaport, float time)
{
	for (const auto& list : mList) {
		list->addRenderOrders(mRaport, time);;
	}
}

void RenderableLists::sortByLayer()
{
	sort(mList.begin(), mList.end(), compareLists);
}

bool RenderableLists::compareLists(RenderableObjectsList* list1, RenderableObjectsList* list2)
{
	if (list1->mLayer < list2->mLayer)
		return true;
	else
		return false;
}