#pragma once

#include <vector>

#include "LayerCode.h"
#include "ViewportCode.h"

#include "LogicRaport.h"
#include "Renderable.h"

//Single list of renderable objects from same Viewport and same Layer
class RenderableObjectsList
{
public:
	RenderableObjectsList(lc mLayer, vpc mViewport);

	vector <Renderable> mList;
	lc mLayer;
	vpc mViewport;
private:

public:
	//Same Viewport and Layer is assumed!
	void add(Renderable newObject);
	//Automatic generation of render order for object
	void addRenderOrders(LogicRaport *mRaport, float time);
};