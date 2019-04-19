#include "InputManager.h"

#include <iostream>

using namespace std;

InputManager::InputManager()
{
	buildDefaultKeyCodesList();
}

void InputManager::calculateInput(InputRaport* mRaport)
{
	calculateActions(mRaport);
	calculateMouse(mRaport);
}

bool InputManager::calculateActions(InputRaport* mRaport)
{
	SDL_Event mEvent;

	while (SDL_PollEvent(&mEvent) != 0)
	{
		if (mEvent.type == SDL_KEYDOWN)
		{
			if (mEvent.key.keysym.sym == SDLK_UP)
			{
				///Input action
			}
				
			mRaport->add(keyCodesList[mEvent.key.keysym.sym]);
		}
		else if (mEvent.type == SDL_MOUSEBUTTONDOWN)
		{
			mRaport->mouseClick = true;
		}
	}

	return true;
}

bool InputManager::calculateMouse(InputRaport* mRaport)
{
	SDL_GetMouseState(&mRaport->mouseX, &mRaport->mouseY);

	return true;
}

void InputManager::buildDefaultKeyCodesList()
{
	///Bind keycodes here
	keyCodesList[SDLK_UP] = MOVE_UP;
	keyCodesList[SDLK_DOWN] = MOVE_DOWN;
	keyCodesList[SDLK_RIGHT] = MOVE_RIGHT;
	keyCodesList[SDLK_LEFT] = MOVE_LEFT;
}