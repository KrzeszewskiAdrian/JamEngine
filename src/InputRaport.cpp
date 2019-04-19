#include "InputRaport.h"

#include <SDL.h>

using namespace std;

void InputRaport::add(inc inputCode)
{
	inputsList.push_back(inputCode);
}