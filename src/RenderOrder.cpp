#include "RenderOrder.h"

#include <iostream>

using namespace std;

RenderOrder::RenderOrder(lc mLayer, string mName, PosRect mRect, float rotation, float alpha, vpc mViewport)
{
	isAnimated = false;
	isText = false;

	this->name = mName;

	this->mRect = mRect;
	this->rotation = rotation;
	this->alpha = alpha;
	this->mViewport = mViewport;
	this->mLayer = mLayer;

	this->speed = -0;
	this->offset = NULL;
}

RenderOrder::RenderOrder(lc mLayer, string mName, PosRect mRect, float rotation, float alpha, vpc mViewport, float animationSpeed, float* animationOffset)
{
	isAnimated = true;
	isText = false;

	this->name = mName;

	this->mRect = mRect;
	this->rotation = rotation;
	this->alpha = alpha;
	this->mViewport = mViewport;
	this->mLayer = mLayer;

	this->speed = animationSpeed;
	this->offset = animationOffset;
}

RenderOrder::RenderOrder(lc mLayer, string mFont, PosRect mRect, float rotation, float alpha, vpc mViewport, float fontSize, string mText)
{
	isAnimated = false;
	isText = true;

	this->name = mFont;

	this->mRect = mRect;
	this->rotation = rotation;
	this->alpha = alpha;
	this->mViewport = mViewport;
	this->mLayer = mLayer;

	this->speed = -0;
	this->offset = NULL;

	this->fontSize = fontSize;
	this->text = mText;
}
