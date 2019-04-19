#pragma once

#include <vector>
#include <algorithm>

#include "RenderOrder.h"

using namespace std;

//Pack of multiple orders for RenderManager
class RenderOrderPack
{
public:
	RenderOrderPack();
	bool put(RenderOrder order);
	vector <RenderOrder> ordersList;

private:
	float time;
public:
	//sort by layer; Sort to ensure correct order of drawing
	void sortBackToFront();
	static bool compareOrders(RenderOrder order1, RenderOrder order2);

	float getTime() { return time; };
	void setTime(float newTime) { this->time = newTime; };
};