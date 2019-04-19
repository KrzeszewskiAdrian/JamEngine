#include "RenderOrderPack.h"

#include <algorithm> 

using namespace std;

RenderOrderPack::RenderOrderPack()
{


}

bool RenderOrderPack::put(RenderOrder order)
{
	ordersList.push_back(order);

	return true;
}

void RenderOrderPack::sortBackToFront()
{
	sort(ordersList.begin(), ordersList.end(), compareOrders);
}

bool RenderOrderPack::compareOrders(RenderOrder order1, RenderOrder order2)
{
	if (order1.mViewport == order2.mViewport)
	{
		if (order1.mLayer < order2.mLayer)
			return true;
		else
			return false;
	}
	else
	{
		if (order1.mViewport < order2.mViewport)
			return true;
		else
			return false;
	}
		
}