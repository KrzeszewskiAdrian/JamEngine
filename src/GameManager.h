#pragma once

#include "LogicManager.h"
#include "RenderManager.h"
#include "SoundManager.h"

#include "InitSettings.h"
#include "Settings.h"
#include "RenderSettings.h"

#include "RayCastMap.h"

//Collecting settings and running crucial managers
class GameManager
{
private:
	LogicManager mLogicManager;
	RenderManager mRenderManager;
	SoundManager mSoundManager;

public:
	GameManager();
	RenderManager* init(RenderSettings settings);
	bool loading(InitSettings initSettings);
	bool runGame(Settings settings);
private:
	bool setUpLogic(Settings settings);
};