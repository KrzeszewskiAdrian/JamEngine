#pragma once

#include <vector>
#include "CameraOrder.h"

using namespace std;

class CameraOrderPack
{
public:
	CameraOrderPack();
	bool put(CameraOrder order);
	vector <CameraOrder> ordersList;

	
};