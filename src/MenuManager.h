#pragma once

#include "RenderManager.h"
#include "Settings.h"

//Manager for menu
class MenuManager
{
public:
	MenuManager();
	int init();
	Settings runMenu(RenderManager* renderer);
};