#include "InitSettings.h"
#include <string>

#include "AnimationSettings.h"

InitSettings::InitSettings()
{
	screenWidth = 1920;
	screenHeight = 1810;
	windowWidth = 1920;
	windowHeight = 1080;
}

bool InitSettings::init()
{
	//Getting graphic options
	if (!takeInitSettings())
		return false;
	//Getting loading textures names
	if (!takeInitTextureList())
		return false;
	if (!takeTextureList())
		return false;
	if (!takeAnimationList())
		return false;
	if (!takeFontList())
		return false;
	if (!takeSoundsList())
		return false;
	return true;
}

bool InitSettings::takeInitSettings()
{
	fstream initFilesettings;
	initFilesettings.open("./Resources/Init/init_settings.txt", ios::in);
	if (initFilesettings.is_open())
	{
		std::string xResolution;
		std::string yResolution;
		std::string fullscreenCode;
		getline(initFilesettings, xResolution);
		getline(initFilesettings, yResolution);
		getline(initFilesettings, fullscreenCode);
		screenWidth = atoi(xResolution.c_str());
		screenHeight = atoi(yResolution.c_str());
		if (fullscreenCode.length() == 14) {
			fullscreen = true;
			windowHeight = screenHeight;
			windowWidth = screenWidth;
		}
		else {
			fullscreen = false;
		}
	}
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Settings init file cannot be opened",
			NULL);
		return false;
	}

	calculateViewports();

	return true;
}

bool InitSettings::takeInitTextureList()
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
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Texture init file cannot be opened",
			NULL);
		return false;
	}
	return true;
}

bool InitSettings::takeTextureList()
{
	std::fstream initFileTextures2;
	initFileTextures2.open("./Resources/Init/init_textures_2.txt", ios::in);
	if (initFileTextures2.is_open())
	{
		std::string textureName;
		while (!initFileTextures2.eof()) {
			getline(initFileTextures2, textureName);
			textureNamesList.push_back(textureName);
		}
		initFileTextures2.close();
	}
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Texture init file cannot be opened",
			NULL);
		return false;
	}
	return true;
}

bool InitSettings::takeFontList()
{
	std::fstream initFileFonts;
	initFileFonts.open("./Resources/Init/init_fonts.txt", ios::in);
	if (initFileFonts.is_open())
	{
		std::string fontName;
		while (!initFileFonts.eof()) {
			getline(initFileFonts, fontName);
			fontNamesList.push_back(fontName);
		}
		initFileFonts.close();
	}
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Font init file cannot be opened",
			NULL);
		return false;
	}
	return true;
}

bool InitSettings::takeSoundsList()
{
	std::fstream initFileSounds;
	initFileSounds.open("./Resources/Init/init_effects.txt", ios::in);
	if (initFileSounds.is_open())
	{
		std::string soundName;
		while (!initFileSounds.eof()) {
			getline(initFileSounds, soundName);
			soundNamesList.push_back(soundName);
		}
		initFileSounds.close();
	}
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Sounds init file cannot be opened",
			NULL);
		return false;
	}
	return true;
}

bool InitSettings::takeAnimationList()
{
	std::fstream initFileAnimations;
	initFileAnimations.open("./Resources/Init/init_animations.txt", ios::in);
	if (initFileAnimations.is_open())
	{
		std::string animationName;
		std::string supportString;
		int numberOfClips;
		int clipWidth;
		int clipHeight;

		while (!initFileAnimations.eof()) 
		{
			getline(initFileAnimations, animationName);

			getline(initFileAnimations, supportString);
			numberOfClips = stoi(supportString, nullptr, 10);

			getline(initFileAnimations, supportString);
			clipWidth = stoi(supportString, nullptr, 10);

			getline(initFileAnimations, supportString);
			clipHeight = stoi(supportString, nullptr, 10);

			AnimationSettings newAnimation(animationName, numberOfClips, clipWidth, clipHeight);

			animationSettingsList.push_back(newAnimation);
		}
		initFileAnimations.close();

	}
	else {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Animation init file cannot be opened",
			NULL);
		return false;
	}
	return true;
}


void InitSettings::calculateViewports()
{
/// VPC_UNDEFINED
	SDL_Rect newRect0 = { 0, 0, 100, 100 };
	viewportSettingsList.push_back(newRect0);
/// First Viewport - LOADING_MAIN
	SDL_Rect newRect1 = {
		0,
		0,
		100,
		1080, 
	};
	viewportSettingsList.push_back(newRect1);

/// GAME_MAIN
	SDL_Rect newRect2 = {
		0,
		0,
		windowWidth,
		windowHeight
	};
	viewportSettingsList.push_back(newRect2);

/// GAME_RESOURCES
	SDL_Rect newRect3 = {
		windowWidth - (int)(windowHeight * 0.2315),
		0,
		(int)(windowHeight * 0.2315),
		windowHeight - (int)(windowHeight * 0.3982)
		
	};
	viewportSettingsList.push_back(newRect3);

/// GAME_ACTIONS
	SDL_Rect newRect4 = {
		windowWidth - (int)(windowHeight * 0.2315),
		windowHeight - (int)(windowHeight * 0.3982),
		(int)(windowHeight * 0.2315),
		(int)(windowHeight * 0.3982)
		
	};
	viewportSettingsList.push_back(newRect4);

}