#pragma once

#include <vector>
#include "SoundOrder.h"

using namespace std;

class SoundOrderPack
{
public:
	SoundOrderPack();
	bool put(SoundOrder order);
	vector <SoundOrder> ordersList;
};