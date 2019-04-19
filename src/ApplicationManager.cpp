#include "ApplicationManager.h"
#include "GameManager.h"
#include "MenuManager.h"
#include "RenderManager.h"

#include "InitSettings.h"
#include "Settings.h"
#include "RenderSettings.h"

using namespace std;

ApplicationManager::ApplicationManager()
{

}

bool ApplicationManager::init()
{

	return true;
}

bool ApplicationManager::runApplication()
{
	bool initSuccesFlag = true;
	GameManager mGameManager;
	MenuManager mMenuManager;

	RenderSettings renderSettings = takeRenderSettings();

	RenderManager *renderer = mGameManager.init(renderSettings);
	if (renderer == NULL)
		initSuccesFlag = false;

	InitSettings initSettings = takeInitSettings();

	mGameManager.loading(initSettings);

	if (!mMenuManager.init())
		initSuccesFlag = false;

	Settings settings = mMenuManager.runMenu(renderer);

	if (!mGameManager.runGame(settings))
		initSuccesFlag = false;
	
	return initSuccesFlag;
}

RenderSettings ApplicationManager::takeRenderSettings()
{
	RenderSettings renderSettings;
	renderSettings.init();

	return renderSettings;
}

InitSettings ApplicationManager::takeInitSettings()
{
	InitSettings initSettings;
	initSettings.init();

	return initSettings;
}