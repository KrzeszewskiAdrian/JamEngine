#include "ClickableLists.h"

void ClickableLists::add(ClickableObjectsList* newList)
{
	mList.push_back(newList);
	sorted = false;
}

void ClickableLists::renderAllLists(LogicRaport *mRaport, float time)
{
	for (const auto& list : mList) {
		list->addRenderOrders(mRaport, time);;
	}
}

Clickable* ClickableLists::identifyObjectClicked(PanelClicksList clicksList, int x, int y)
{
	clicksList.sortByViewports();
	if (!sorted)
	{
		sortByLayer();
		sorted = true;
	}

	for (int k = 0; k < clicksList.mList.size(); k++)
	{
		for (int j = mList.size() - 1; j >= 0; j--) 
		{
			if ((mList[j]->mViewport == clicksList.mList[k].mPanel) || (mList[j]->mViewport == VPC_UNDEFINED)) {
				for (int i = 0; i < mList[j]->mList.size(); i++) 
				{
					if ((mList[j]->mList[i].mViewport == clicksList.mList[k].mPanel) && (mList[j]->mList[i].checkIfPointIn(clicksList.mList[k].x, clicksList.mList[k].y)))
					{
						return &mList[j]->mList[i];
					}
				}
			}
		}
	}

	return NULL;
}

Clickable* ClickableLists::identifyObjectMouseOver(PanelClicksList clicksList, int x, int y)
{
	clicksList.sortByViewports();
	if (!sorted)
	{
		sortByLayer();
		sorted = true;
	}

	for (int k = 0; k < clicksList.mList.size(); k++)
	{
		for (int j = mList.size() - 1; j >= 0; j--)
		{
			if ((mList[j]->mViewport == clicksList.mList[k].mPanel) || (mList[j]->mViewport == VPC_UNDEFINED)) {
				for (int i = 0; i < mList[j]->mList.size(); i++)
				{
					if ((mList[j]->mList[i].mViewport == clicksList.mList[k].mPanel) && (mList[j]->mList[i].checkIfPointIn(clicksList.mList[k].x, clicksList.mList[k].y)))
					{
						return &mList[j]->mList[i];
					}
				}
			}
		}
	}

	return NULL;
}

void ClickableLists::sortByLayer()
{
	sort(mList.begin(), mList.end(), compareLists);
}

bool ClickableLists::compareLists(ClickableObjectsList* list1, ClickableObjectsList* list2)
{
	if (list1->mLayer < list2->mLayer)
		return true;
	else
		return false;
}