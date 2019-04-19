#pragma once

#include <SDL.h>

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "AnimationSettings.h"

using namespace std;

//Class for reading and storing init data from init files
class InitSettings
{
public:
	InitSettings();

	vector <string> initTextureNamesList;
	vector <string> textureNamesList;
	vector <string> fontNamesList;
	vector <string> soundNamesList;
	vector <AnimationSettings> animationSettingsList;

	vector <SDL_Rect> viewportSettingsList;

	bool init();
	bool takeInitSettings();

	bool takeInitTextureList();
	bool takeTextureList();
	bool takeFontList();
	bool takeSoundsList();
	bool takeAnimationList();
private:
	int screenWidth;
	int screenHeight;
	int windowWidth;
	int windowHeight;
	bool fullscreen;
public:
	int getScreenWidth() { return screenWidth; };
	int getScreenHeight() { return screenHeight; };
	int getWindowWidth() { return windowWidth; };
	int getWindowHeight() { return windowHeight; };
private:
	//Setting up Viewports sizes
	void calculateViewports();
};