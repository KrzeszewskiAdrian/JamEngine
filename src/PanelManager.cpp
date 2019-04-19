#include "PanelManager.h"

#include "PanelClick.h"

#include "ViewportCode.h"

using namespace std;

void PanelManager::add(vpc mViewport, SDL_Rect panelRect)
{
	Panel newPanel(mViewport, &panelRect);
	mList[mViewport] = newPanel;
}

void PanelManager::add(vpc mViewport, SDL_Rect panelRect, SDL_Rect cameraRect)
{
	Panel newPanel(mViewport, &panelRect, &cameraRect);
	mList[mViewport] = newPanel;
}

PanelClicksList PanelManager::calculatePanelClicks(int x, int y)
{
	PanelClicksList newPanelClicksList;

	for (auto& panel : mList) {
		if (panel.second.checkIfIn(x, y))
		{
			double calculatedX = 100.0 * ((x - panel.second.getPanelRect()->x) + panel.second.getCameraRect()->x) / panel.second.getPanelRect()->w;
			double calculatedY = 100.0 * ((y - panel.second.getPanelRect()->y) + panel.second.getCameraRect()->y) / panel.second.getPanelRect()->h;

			PanelClick newPanelClick(panel.first, calculatedX, calculatedY);
			newPanelClicksList.add(newPanelClick);
		}
	}

	return newPanelClicksList;
}