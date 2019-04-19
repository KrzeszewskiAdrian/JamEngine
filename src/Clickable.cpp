#include "Clickable.h"

Clickable::Clickable(lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport, PosRect clickRect, cbc clickBoxCode)
	: Renderable (mLayer, textureName, textureRect, newAlpha, newRotation, newViewport)
{
	this->clickRect.x = clickRect.x;
	this->clickRect.y = clickRect.y;
	this->clickRect.w = clickRect.w;
	this->clickRect.h = clickRect.h;
	this->clickboxCode = clickBoxCode;
}

Clickable::Clickable(lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport, float newAnimationSpeed, float newAnimationOffset, SDL_Rect clickRect, cbc clickBoxCode)
	: Renderable (mLayer, textureName, textureRect, newAlpha, newRotation, newViewport, newAnimationSpeed, newAnimationOffset)
{
	this->clickRect.x = clickRect.x;
	this->clickRect.y = clickRect.y;
	this->clickRect.w = clickRect.w;
	this->clickRect.h = clickRect.h;
	this->clickboxCode = clickBoxCode;
}

bool Clickable::checkIfPointIn(int clickedX, int clickedY)
{
	if (clickRect.x < clickedX && clickRect.x + clickRect.w > clickedX && clickRect.y < clickedY && clickRect.y + clickRect.h > clickedY)
	{
		if(clickboxCode == RECT)
			return true;
	}
	return false;
}

void Clickable::setFullRectClickbox()
{
	clickboxCode = RECT;
	clickRect = mRect;
}

void Clickable::setFixedRectClickbox(int x, int y, int w, int h)
{
	if (w < 0 || h < 0){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Clickbox size cannot be smaller than 0!",
			NULL);
	}

	clickboxCode = RECT;
	clickRect.x = x;
	clickRect.y = y;
	clickRect.w = w;
	clickRect.h = h;
}

void Clickable::setFullCircleClickbox()
{
	clickboxCode = CIRCLE;
	clickRect = mRect;
}

void Clickable::setFixedCircleClickbox(int x, int y, int w)
{
	if (w < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Clickbox size cannot be smaller than 0!",
			NULL);
	}
		
	clickboxCode = CIRCLE;
	clickRect.x = x;
	clickRect.y = y;
	clickRect.w = w;
	clickRect.h = w;
}

