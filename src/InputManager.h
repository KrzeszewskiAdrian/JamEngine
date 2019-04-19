#pragma once

#include <SDL.h>

#include <stdio.h>
#include <string>
#include <map>

#include "InputRaport.h"
#include "InputCode.h"

class InputManager
{
public:
	InputManager();
private:
	//Stores current keybind configuration
	std::map<SDL_Keycode, inc> keyCodesList;

	//Builds default keybind configuration
	void buildDefaultKeyCodesList();
public:
	
	//Fills up InputRaport with current actions and mouse position
	void calculateInput(InputRaport* mRaport);

	bool calculateActions(InputRaport* mRaport);
	bool calculateMouse(InputRaport* mRaport);
};
