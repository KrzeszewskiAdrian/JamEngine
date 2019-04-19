#pragma once

#include <vector>
#include <algorithm>

#include "PanelClick.h"

using namespace std;

//A mouse Click performed within borders of multiple Panels
class PanelClicksList
{
public:
	vector <PanelClick> mList;
private:

public:
	void add(PanelClick newPanelClick);

	//Sort by viewport to determine clicked object in front
	void sortByViewports();
	static bool compareClicks(PanelClick click1, PanelClick click2);

};