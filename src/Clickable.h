#pragma once
#include <SDL.h>

#include "Renderable.h"

#include "PosRect.h"

#include "ClickboxCode.h"
#include "LayerCode.h"
#include "ViewportCode.h"

//Interface for renderable and clickable objects
class Clickable : public Renderable
{
public:
	//Constructor for texture
	Clickable(lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport, PosRect clickRect, cbc clickBoxCode);
	//Constructor for animation
	Clickable(lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport, float newAnimationSpeed, float newAnimationOffset, SDL_Rect clickRect, cbc clickBoxCode);

	//Checking if given point is inside object. Used to test if mouse is hovering over, or object was clicked.
	bool checkIfPointIn(int x, int y);

	//Setting rectangle clickbox same size as an object
	void setFullRectClickbox();
	//Setting rectangle clickbox with fixed sides lenght
	void setFixedRectClickbox(int x, int y, int w, int h);
	//Setting circle clickbox with biggest size object can fit
	void setFullCircleClickbox();
	//Setting circle clickbox with fixed size
	void setFixedCircleClickbox(int x, int y, int w);
protected:
	//Type of clickbox
	cbc clickboxCode;
	//Clickbox Rect; relative to object's Rect
	PosRect clickRect;
};