#include <iostream>
#include "LogicManager.h"
#include "LogicRaport.h"
#include "Settings.h"
#include "Timer.h"
#include "ViewportCode.h"

#include "Renderable.h"

#include "RenderableLists.h"
#include "ClickableLists.h"

#include "TestObject.h"
#include <stdlib.h>
#include <time.h>   


using namespace std;

LogicManager::LogicManager()
{
	srand(time(NULL));


}

bool LogicManager::initManager(InitSettings settings)
{
	//LOADING_MAIN
	PanelManager.add(LOADING_MAIN, { settings.viewportSettingsList[LOADING_MAIN] });
	//GAME_MAIN
	PanelManager.add(GAME_MAIN, { settings.viewportSettingsList[GAME_MAIN] });
	//GAME_RESOURCES
	PanelManager.add(GAME_RESOURCES, { settings.viewportSettingsList[GAME_RESOURCES] });
	//GAME_ACTIONS
	PanelManager.add(GAME_ACTIONS, { settings.viewportSettingsList[GAME_ACTIONS] });

	return true;
}

bool LogicManager::initGame(Settings settings)
{

	return true;
}



int LogicManager::loading(Settings settings)
{
	testOffset = 3.0;
	return 100;
}


LogicRaport LogicManager::calculateLogic()
{

	mLogicRaport = new LogicRaport();
	mInputRaport = new InputRaport();

///Time insensitive calculations
	InputManager.calculateInput(mInputRaport);
	
	clickedObject = NULL;
	hoveredObject = NULL;
	translateInput();

	calculateTimeInsensitive();
///Take current time
	mTimer.startLoop();

	oneHundredFramesTime = oneHundredFramesTime + mTimer.getLastLoopDuration();
	
///Time sensitive calculations

	currentLoopTime = mTimer.getLastLoopDuration();

	mLogicRaport->setTime(currentLoopTime);

	calculateTimeSensitive();

	///Generating orders from lists
	mRenderableLists.renderAllLists(mLogicRaport, currentLoopTime);
	mClickableLists.renderAllLists(mLogicRaport, currentLoopTime);

	frame++;

	return *mLogicRaport;
}

bool LogicManager::calculateTimeInsensitive()
{
	//Main code starts from here
	//see https://github.com/KrzeszewskiAdrian/JamEngine for help
	


	return true;
}

bool LogicManager::calculateTimeSensitive()
{
	//Main code starts from here
	//see https://github.com/KrzeszewskiAdrian/JamEngine for help



	return true;
}

bool LogicManager::adjustPanels()
{
	PanelManager.mList[LOADING_MAIN].move(currentLoopTime);

	CameraOrder testOrder7(LOADING_MAIN);
	testOrder7.jump(PanelManager.mList[LOADING_MAIN].getCameraX(), PanelManager.mList[LOADING_MAIN].getCameraY());
	//mLogicRaport->add(testOrder7);

	return true;
}



void LogicManager::translateInput()
{
	PanelClicksList panelClicksList = PanelManager.calculatePanelClicks(mInputRaport->mouseX, mInputRaport->mouseY);

	if (mInputRaport->mouseClick == true)
	{
		clickedObject = mClickableLists.identifyObjectClicked(panelClicksList, mInputRaport->mouseX, mInputRaport->mouseY);

	}
	else
	{
		hoveredObject = mClickableLists.identifyObjectClicked(panelClicksList, mInputRaport->mouseX, mInputRaport->mouseY);

	}
}

