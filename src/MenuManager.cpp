#include <iostream>
#include "MenuManager.h"

#include "RenderManager.h"
#include "Settings.h"

using namespace std;

MenuManager::MenuManager()
{

}

int MenuManager::init()
{

	return true;
}

Settings MenuManager::runMenu(RenderManager* renderer)
{
	Settings gameSettings;

	return gameSettings;
}
