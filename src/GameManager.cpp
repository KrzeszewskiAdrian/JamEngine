#include "GameManager.h"
#include "LogicManager.h"
#include "RenderManager.h"
#include "LogicRaport.h"
#include "InitSettings.h"
#include "Settings.h"

using namespace std;

GameManager::GameManager()
{


}

RenderManager* GameManager::init(RenderSettings settings)
{
	if(!mRenderManager.init(settings));
		return NULL;

	return & mRenderManager;
}

bool GameManager::loading(InitSettings initSettings)
{
	bool initSuccesFlag = true;

	///Loading Render loop:
	int loadingStatus = 0;
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"SDL Audio initialization erro",
			NULL);
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"SDL Audio initialization erro",
			NULL);
	}

	mSoundManager.loading(initSettings);

	Mix_AllocateChannels(16);

	mRenderManager.initViewports(initSettings);
	mLogicManager.initManager(initSettings);

	while (initSuccesFlag == true && loadingStatus != 100)
	{
		loadingStatus = mRenderManager.loading(initSettings);
		if (loadingStatus < 0)
			initSuccesFlag = false;
	}

	return initSuccesFlag;
}

bool GameManager::runGame(Settings settings)
{
	if (!setUpLogic(settings))
		return false;

	///MAIN LOOP:
	LogicRaport currentRaport;
	do {
		currentRaport = mLogicManager.calculateLogic();
		mRenderManager.renderGame(currentRaport.getCameraOrderPack(), currentRaport.getRenderOrderPack());
		mSoundManager.playSounds(currentRaport.getSoundOrderPack());

	} while (!currentRaport.isGameFinished);

	return true;
}

bool GameManager::setUpLogic(Settings settings)
{
	bool initSuccesFlag = true;

	if (!mLogicManager.initGame(settings))
		initSuccesFlag = false;

///Loading Logic loop:
	int loadingStatus = 0;
	while (initSuccesFlag == true && loadingStatus != 100)
	{
		loadingStatus = mLogicManager.loading(settings);
		if (loadingStatus < 0)
			initSuccesFlag = false;
		mRenderManager.showLoading(loadingStatus);
	}

	return initSuccesFlag;
}