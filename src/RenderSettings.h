#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Pack of settings to initialize RenderManager
class RenderSettings
{
public:
	RenderSettings();

	//Textures names from init file
	vector <string> initTextureNamesList;
	//Animations names from init file
	vector <string> initAnimationNamesList;

	bool init();
	bool takeInitSettings();

	//Opening and reading init file
	bool takeInitTextureList();
	//Opening and reading init file
	bool takeInitAnimationList();
private:
	int screenWidth;
	int screenHeight;
	int windowWidth;
	int windowHeight;
public:
	int getScreenWidth() { return screenWidth; };
	int getScreenHeight() { return screenHeight; };
	int getWindowWidth() { return windowWidth; };
	int getWindowHeight() { return windowHeight; };
};