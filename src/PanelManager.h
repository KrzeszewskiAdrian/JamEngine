#pragma once

#include <SDL.h>
#include <string>
#include <map>

#include "Panel.h"
#include "Renderable.h"

#include "PanelClicksList.h"
#include "PanelClick.h"

#include "ViewportCode.h"



//Not all methods moved to this manager
class PanelManager
{
public:
	map<vpc, Panel> mList;

private:

public:
	//Camera equal to whole viewport
	void add(vpc mViewport, SDL_Rect panelRect);
	//Non-default camera
	void add(vpc mViewport, SDL_Rect panelRect, SDL_Rect cameraRect);
	//May return multiple Viewports!
	PanelClicksList calculatePanelClicks(int x, int y);


};