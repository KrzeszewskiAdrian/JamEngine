#include "Renderable.h"

#include <iostream>

#include "RenderOrder.h"

Renderable::Renderable(lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport)
{
	visable = true;

	this->mLayer = mLayer;
	this->textureName = textureName;
	this->mRect = textureRect;
	this->alpha = newAlpha;
	this->rotation = newRotation;
	this->mViewport = newViewport;

	this->isAnimated = false;
}

Renderable::Renderable(lc mLayer, string textureName, PosRect textureRect, float newAlpha, float newRotation, vpc newViewport, float newAnimationSpeed, float newAnimationOffset)
{
	visable = true;

	this->mLayer = mLayer;
	this->textureName = textureName;
	this->mRect = textureRect;
	this->alpha = newAlpha;
	this->rotation = newRotation;
	this->mViewport = newViewport;

	this->animationSpeed = newAnimationSpeed;
	this->animationOffset = newAnimationOffset;

	this->isAnimated = true;
}

RenderOrder Renderable::generateRenderOrder()
{
	if (this->isAnimated)
	{
		RenderOrder newOrder(mLayer, textureName, mRect, rotation, alpha, mViewport, animationSpeed, &animationOffset);
		return newOrder;
	}
	else
	{
		RenderOrder newOrder(mLayer, textureName, mRect, rotation, alpha, mViewport);
		return newOrder;
	}
}