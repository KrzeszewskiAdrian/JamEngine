#include "Timer.h"

using namespace std;

float Timer::getTotalTime() {
	return ((float)clock()) / (CLOCKS_PER_SEC / 1000);
};

void Timer::startLoop() {
	if (startLoopTime != 0) {
		float newStartLoopTime = getTotalTime();
		lastLoopDuration = newStartLoopTime - startLoopTime;
		startLoopTime = newStartLoopTime;
	}
	else {
		startLoopTime = getTotalTime();
		lastLoopDuration = 0;
	}
}

float Timer::getLoopTime() {
	return (getTotalTime() - startLoopTime);
}

float Timer::getLastLoopDuration() {
	return lastLoopDuration;
}