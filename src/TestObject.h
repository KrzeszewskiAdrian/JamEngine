#pragma once

#include "Renderable.h"

#include "LayerCode.h"

class TestObject : public Renderable
{
public:
	TestObject(lc mLayer, string textureName, PosRect mRect, float newAlpha, float newRotation, vpc newViewport)
		: Renderable(mLayer, textureName, mRect, newAlpha, newRotation, newViewport)
	{	}
	TestObject(lc mLayer, string textureName, PosRect mRect, float newAlpha, float newRotation, vpc newViewport, float newAnimationSpeed, float newAnimationOffset)
		: Renderable(mLayer, textureName, mRect, newAlpha, newRotation, newViewport, newAnimationSpeed, newAnimationOffset)
	{	}
};