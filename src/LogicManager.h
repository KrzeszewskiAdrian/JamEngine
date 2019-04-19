#pragma once

#include <ctime>

#include "LogicRaport.h"
#include "Timer.h"
#include "InputManager.h"
#include "PanelManager.h"

#include "InitSettings.h"
#include "Settings.h"
#include "Viewport.h"
#include "Panel.h"

#include <map>

#include "Renderable.h"

#include "RenderableLists.h"
#include "ClickableLists.h"

#include "RenderableObjectsList.h"

#include "QuickAnimation.h"

#include "RayCastMap.h"

#include "TestObject.h"


//Main class for game's logic
class LogicManager
{
public:
	LogicManager();
	bool initManager(InitSettings settings);
	bool initGame(Settings settings);
	//Returns loaded portion in %. May be used to show porgress bar between loading portions
	int loading(Settings settings);

	LogicRaport calculateLogic();

	//All calculations that don't use time factor should be executed from here!
	bool calculateTimeInsensitive();
	//All calculations that use time factor should be executed from here!
	bool calculateTimeSensitive();

	//Moves camera if needed
	bool adjustPanels();

	//Setting clickedObject and hoveredObject
	void translateInput();
private:
	//Raport from current frame
	LogicRaport* mLogicRaport;
	InputRaport* mInputRaport;

	//All renderable lists should be putted on this main list
	RenderableLists mRenderableLists;
	//All clickable lists should be putted on this main list
	ClickableLists mClickableLists;

	Timer mTimer;
	InputManager InputManager;
	PanelManager PanelManager;

	float testOffset;
	RenderableObjectsList * testList;

	//Time since last frame
	float currentLoopTime;

	int frame = 0;
	//Used to calculate FPS value
	int oneHundredFramesTime = 0;

	//Currently clicked object
	Clickable* clickedObject = NULL;
	//Object that mouse is hovering over now
	Clickable* hoveredObject = NULL;
};