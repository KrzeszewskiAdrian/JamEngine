#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <map>

#include "InitSettings.h"
#include "Settings.h"
#include "RenderSettings.h"

#include "Texture.h"
#include "Animation.h"
#include "Font.h"
#include "CameraOrderPack.h"
#include "RenderOrderPack.h"
#include "Viewport.h"
#include "ViewportCode.h"

//Main rendering class
class RenderManager
{
private:
	SDL_Window* mWindow = NULL;
	SDL_Renderer* mRenderer = NULL;

	double fontScale = 1.0;

	///Vaults for resources:
	std::map<std::string, Texture> textureVault;
	std::map<std::string, Animation> animationVault;
	std::map<std::string, Font> fontVault;

	std::map<vpc, Viewport> viewportsList;
public:
	RenderManager();
	bool init(RenderSettings settings);
	void initViewports(InitSettings settings);
	bool initLoading(RenderSettings settings);
	//Returns loaded portion in %. May be used to show porgress bar between loading portions
	int loading(InitSettings settings);
	//Showing loading bar
	void showLoading(int loadingStatus);
	//Renders all orders from raport
	void renderGame(CameraOrderPack CameraOrderPack, RenderOrderPack OrderPack);
	bool render(RenderOrder order, float time);
	//Render method for Texture
	bool renderTexture(RenderOrder order);
	//Render method for Animation
	bool renderAnimation(RenderOrder order, float time);
	//Render method for Text
	bool renderText(RenderOrder order);
	//Render method for single character
	bool renderChar(RenderOrder order, int x, int y, SDL_Rect* clip);
	//Switching viewport befor next portion of rendering
	int mountViewport(vpc viewportCode);

	SDL_Renderer* getRenderer() { return mRenderer; };
private:
	bool SDLInit();
	void close();
};