#include "SoundOrderPack.h"

using namespace std;

SoundOrderPack::SoundOrderPack()
{


}

bool SoundOrderPack::put(SoundOrder order)
{
	ordersList.push_back(order);

	return true;
}