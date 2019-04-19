#pragma once

#include <iostream>

#include "Texture.h"

#include "PosRect.h"
#include "LayerCode.h"
#include "ViewportCode.h"

using namespace std;

//Single order for RenderManager
class RenderOrder
{
public:
	//Constructor for texture
	RenderOrder(lc mLayer, string mName, PosRect mRect, float rotation, float alpha, vpc mViewport);
	//Constructor for animation
	RenderOrder(lc mLayer, string mName, PosRect mRect, float rotation, float alpha, vpc mViewport, float animationSpeed, float* animationOffset);
	//Constructor for text
	RenderOrder(lc mLayer, string mName, PosRect mRect, float rotation, float alpha, vpc mViewport, float fontSize, string mText);



	lc mLayer;
	vpc mViewport;
	bool isAnimated;
	bool isText;
private:
	string name;
	string text;
	float time;
	PosRect mRect;
	float rotation;
	float alpha;
	
	float speed;
	//Pointer to unique object's animation offset
	float* offset;

	//1 - 100 % of normal size
	float fontSize;
public:
	string getName() { return name; };
	string getText() { return text; };
	double getX() { return mRect.x; };
	double getY() { return mRect.y; };
	double getWidth() { return mRect.w; };
	double getHeight() { return mRect.h; };
	int getRotation() { return rotation; };
	float getAlpha() { return alpha; };
	float getTime() { return time; };

	float getSpeed() { return speed; };
	float* getOffset() { return offset; };

	float getFontSize() { return fontSize; };
};