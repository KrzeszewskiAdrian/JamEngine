#pragma once

#include <vector>

#include "LayerCode.h"
#include "ViewportCode.h"

#include "LogicRaport.h"
#include "Clickable.h"

#include "RenderableObjectsList.h"

//Single list of clickable objects from same Viewport and same Layer
class ClickableObjectsList
{
public:
	ClickableObjectsList();

	vector <Clickable> mList;
	vpc mViewport;
	lc mLayer;
private:

public:
	//Same Viewport and Layer is assumed!
	void add(Clickable newObject);
	//Automatic generation of render orders for objects
	void addRenderOrders(LogicRaport *mRaport, float time);
};