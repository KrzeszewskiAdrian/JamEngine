#pragma once
#include <SDL.h>

#include "RenderOrder.h"

#include "PosRect.h"

#include "LayerCode.h"
#include "ViewportCode.h"

//Interface for renderable objects
class Renderable
{
public:
	//Constructor for static object
	Renderable (lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport);
	//Constructor for animated object
	Renderable (lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport, float newAnimationSpeed, float newAnimationOffset);

	//Automatic generation of render order for this object
	RenderOrder generateRenderOrder();
	string textureName;

	PosRect mRect;

	bool visable;

	lc mLayer;
	vpc mViewport;

protected:
	float alpha;
	float rotation;

	bool isAnimated;
	float animationSpeed;

	///variable used by RenderManager
	//determine current animation frame
	float animationOffset;
};