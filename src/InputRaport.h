#pragma once
#include <SDL.h>

#include <vector>

#include "InputCode.h"

class InputRaport
{
public:
	//True if mouse was clicked in last frame
	bool mouseClick;

	int mouseX;
	int mouseY;
	//All key actions currently performed
	std::vector <inc> inputsList;
private:
	
public:
	void add(inc inputCode);
};