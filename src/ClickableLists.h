#pragma once

#include <vector>

#include "ClickableObjectsList.h"
#include "RenderableLists.h"

#include "PanelClicksList.h"
#include "Clickable.h"

using namespace std;

//List of lists with clickable objects
class ClickableLists
{
public:
	vector <ClickableObjectsList*> mList;
private:
	//Sort with increasing order
	void sortByLayer();
	static bool compareLists(ClickableObjectsList* list1, ClickableObjectsList* list2);

	bool sorted;
public:
	void add(ClickableObjectsList* newList);
	//Automatic generation of renders for all objects from list
	void renderAllLists(LogicRaport *mRaport, float time);
	
	Clickable* identifyObjectClicked(PanelClicksList clicksList, int x, int y);
	Clickable* identifyObjectMouseOver(PanelClicksList clicksList, int x, int y);

};