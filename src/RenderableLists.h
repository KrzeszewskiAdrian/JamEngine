#pragma once

#include <vector>

#include "RenderableObjectsList.h"

#include "Renderable.h"


using namespace std;

//List of lists with renderable objects
class RenderableLists
{
public:
	vector <RenderableObjectsList*> mList;
private:
	//
public:
	//Same Viewport and Layer is assumed!
	void add(RenderableObjectsList* newList);
	//Automatic generation of render order for all objects on list
	void renderAllLists(LogicRaport *mRaport, float time);

	//sort increasing; Sort to ensure correct order of rendering
	void sortByLayer();
	static bool compareLists(RenderableObjectsList* list1, RenderableObjectsList* list2);
};