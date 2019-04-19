#include "RenderSettings.h"
#include <string>

RenderSettings::RenderSettings()
{
	screenWidth = 300;
	screenHeight = 300;
	windowWidth = 1920;
	windowHeight = 1080;
}

bool RenderSettings::init()
{
	//Getting graphic options
	if (!takeInitSettings())
		return false;
	//Getting texture names
	if (!takeInitTextureList())
		return false;
	//Getting animation names
	if (!takeInitAnimationList())
		return false;
	return true;
}

bool RenderSettings::takeInitSettings()
{
	fstream initFilesettings;
	initFilesettings.open("./Resources/Init/init_settings.txt", ios::in);
	if (initFilesettings.is_open())
	{
		std::string xResolution;
		std::string yResolution;
		getline(initFilesettings, xResolution);
		getline(initFilesettings, yResolution);
		screenWidth = atoi(xResolution.c_str());
		screenHeight = atoi(yResolution.c_str());
	}
	else
		return false;
	return true;
}

bool RenderSettings::takeInitTextureList()
{
	fstream initFileTextures;
	initFileTextures.open("./Resources/Init/init_textures_1.txt", ios::in);
	if (initFileTextures.is_open())
	{
		std::string textureName;
		while (!initFileTextures.eof()) {
			getline(initFileTextures, textureName);
			initTextureNamesList.push_back(textureName);
		}
		initFileTextures.close();

	}
	else
		return false;
	return true;
}

bool RenderSettings::takeInitAnimationList()
{
	fstream initFileAnimations;
	initFileAnimations.open("./Resources/Init/init_animations_1.txt", ios::in);
	if (initFileAnimations.is_open())
	{
		std::string animationName;
		while (!initFileAnimations.eof()) {
			getline(initFileAnimations, animationName);
			initAnimationNamesList.push_back(animationName);
		}
		initFileAnimations.close();

	}
	else
		return false;
	return true;
}