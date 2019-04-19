#pragma once
#include <time.h>

class Timer
{
	///All times in milliseconds

private:
	clock_t lastLoopDuration;
	clock_t startLoopTime;
public:
	float getTotalTime();
	void startLoop();
	float getLoopTime();
	float getLastLoopDuration();
};