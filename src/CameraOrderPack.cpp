#include "CameraOrderPack.h"

using namespace std;

CameraOrderPack::CameraOrderPack()
{


}

bool CameraOrderPack::put(CameraOrder order)
{
	ordersList.push_back(order);

	return true;
}