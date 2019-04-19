#include "PanelClicksList.h"

#include <algorithm>



void PanelClicksList::add(PanelClick newPanelClick)
{
	mList.push_back(newPanelClick);
}

void PanelClicksList::sortByViewports()
{
	sort(mList.begin(), mList.end(), compareClicks);
}

bool PanelClicksList::compareClicks(PanelClick click1, PanelClick click2)
{
	if (click1.mPanel < click2.mPanel)
		return true;
	else
		return false;
}
