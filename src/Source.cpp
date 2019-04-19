#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include "ApplicationManager.h"

using namespace std;

int main(int argc, char * argv[])
{


	bool initSuccesFlag = true;

	ApplicationManager mApplicationManager;

	if (!mApplicationManager.init())
		initSuccesFlag = false;

	mApplicationManager.runApplication();

	return 0;
}