#include "RenderManager.h"

#include <map>

#include "Settings.h";
#include "RenderOrderPack.h"

#include <string>

using namespace std;

RenderManager::RenderManager()
{
	
}

bool RenderManager::init(RenderSettings settings)
{
	if (!SDLInit())
		return false;

	mWindow = SDL_CreateWindow("JamEngine Template App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/);
	if (mWindow == NULL){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Window creation error!",
			NULL);
		return false;
	}
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (mRenderer == NULL){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Render creation error!",
			NULL);
		return false;
	}
	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"SDL init error",
			NULL);
		return false;
	}

	if (!initLoading(settings))
		return false;
	return true;
}

bool RenderManager::SDLInit()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return false;
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		return false;
	SDL_AudioInit("waveout");
}

void RenderManager::initViewports(InitSettings settings)
{
	Viewport VPLoadingMain(settings.viewportSettingsList[LOADING_MAIN]);
	viewportsList.insert(std::map< vpc, Viewport>::value_type(LOADING_MAIN, VPLoadingMain));
	Viewport VPGameMain(settings.viewportSettingsList[GAME_MAIN]);
	viewportsList.insert(std::map< vpc, Viewport>::value_type(GAME_MAIN, VPGameMain));
	Viewport VPGameResources(settings.viewportSettingsList[GAME_RESOURCES]);
	viewportsList.insert(std::map< vpc, Viewport>::value_type(GAME_RESOURCES, VPGameResources));
	Viewport VPGameActions(settings.viewportSettingsList[GAME_ACTIONS]);
	viewportsList.insert(std::map< vpc, Viewport>::value_type(GAME_ACTIONS, VPGameActions));
}

bool RenderManager::initLoading(RenderSettings settings)
{
	for (const auto& name : settings.initTextureNamesList) {
		Texture newTexture;
		if (!newTexture.load(mRenderer, name)) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Texture loading error",
				NULL);
			return false;
		}

		textureVault[name] = newTexture;
	}
	return true;
}

int RenderManager::loading(InitSettings settings)
{
///Loading textures
	for (const auto& name : settings.textureNamesList) {
		Texture newTexture;
		if (!newTexture.load(mRenderer, name)){
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Texture loading error",
				NULL);
			return -1;
		}
		textureVault[name] = newTexture; 
	}
///Loading animatios
	for (const auto& animationSettings : settings.animationSettingsList) {
		Animation newAnimation(animationSettings.width, animationSettings.height, animationSettings.numberOfClips);
		if (!newAnimation.load(mRenderer, animationSettings.name)) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Animation loading error",
				NULL);
			return -1;
		}
		animationVault[animationSettings.name] = newAnimation;
	}
///Loading fonts
	for (const auto& name : settings.fontNamesList) {
		Font newFont;
		if (!newFont.load(mRenderer, name)) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Font loading error",
				NULL);
			return -1;
		}
		fontVault[name] = newFont;
	}
	return 100;
}

void RenderManager::showLoading(int loadingStatus)
{

}

void RenderManager::renderGame(CameraOrderPack CameraOrderPack, RenderOrderPack RenderOrderPack)
{
	RenderOrderPack.sortBackToFront();
	SDL_RenderClear(mRenderer);
///Camera orders:
	for (const auto& order : CameraOrderPack.ordersList) {
		viewportsList.find(order.viewportCode)->second.mCamera->executeOrder(order);
	}

	for (const auto& viewport : viewportsList) {
		viewport.second.mCamera->adjust(RenderOrderPack.getTime());
	}

///Render orders:
	vpc currentViewport = VPC_UNDEFINED;
	for (const auto& order : RenderOrderPack.ordersList) {
		if (order.mViewport != currentViewport) {
			currentViewport = order.mViewport;
			mountViewport(currentViewport);
		}
		render(order, RenderOrderPack.getTime());
	}

	SDL_RenderPresent(mRenderer);
}

bool RenderManager::render(RenderOrder order, float time)
{
	if (order.isAnimated == true)
		renderAnimation(order, time);
	else if (order.isText == true)
		renderText(order);
	else
		renderTexture(order);
		
	return true;
}

bool RenderManager::renderTexture(RenderOrder order)
{
	SDL_Rect mQuad = { 
		(order.getX()/100.0) * viewportsList.find(order.mViewport)->second.mRect->w - viewportsList.find(order.mViewport)->second.mCamera->mRect->x,
		(order.getY()/100.0) * viewportsList.find(order.mViewport)->second.mRect->h - viewportsList.find(order.mViewport)->second.mCamera->mRect->y,
		(order.getWidth()/100.0) * viewportsList.find(order.mViewport)->second.mRect->w,
		(order.getHeight()/100.0) * viewportsList.find(order.mViewport)->second.mRect->h };
	SDL_Point* mCenter = NULL;
	SDL_RendererFlip mFlip = SDL_FLIP_NONE;

	SDL_RenderCopyEx(
		mRenderer,
		textureVault[order.getName()].mTexture,
		NULL,
		&mQuad,
		order.getRotation(),
		mCenter,
		mFlip);

	return true;
}

bool RenderManager::renderAnimation(RenderOrder order, float time)
{
	SDL_Rect mQuad = { 
		(order.getX() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->w - viewportsList.find(order.mViewport)->second.mCamera->mRect->x,
		(order.getY() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->h - viewportsList.find(order.mViewport)->second.mCamera->mRect->y,
		(order.getWidth() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->w,
		(order.getHeight() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->h };
	SDL_Point* mCenter = NULL;
	SDL_RendererFlip mFlip = SDL_FLIP_NONE;

	animationVault[order.getName()].updateOffset(time, order.getSpeed(), order.getOffset());

	SDL_RenderCopyEx(
		mRenderer,
		animationVault[order.getName()].mTexture[(int)*order.getOffset()],
		NULL,
		&mQuad,
		order.getRotation(),
		mCenter,
		mFlip);

	return true;
}


bool RenderManager::renderText(RenderOrder order)
{
	//If the font has been built
	if (fontVault[order.getName()].mTexture == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Font is missing",
			NULL);
		return false;
	}
	//Temp offsets
	double currentX = (order.getX() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->w - viewportsList.find(order.mViewport)->second.mCamera->mRect->x;
	double currentY = (order.getY() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->h - viewportsList.find(order.mViewport)->second.mCamera->mRect->y;

	//Go through the text
	for (int i = 0; i < order.getText().length(); ++i)
	{
		//If the current character is a space
		if (order.getText()[i] == ' ')
		{
			//Move over
			currentX += (fontVault[order.getName()].getSpace()) * fontScale * order.getFontSize();
		}
		//If the current character is a newline
		else if (order.getText()[i] == '$')
		{
			//Move down
			currentY += (fontVault[order.getName()].getNewLine()) * fontScale * order.getFontSize();

			//Move back
			currentX = (order.getX() / 100.0) * viewportsList.find(order.mViewport)->second.mRect->w - viewportsList.find(order.mViewport)->second.mCamera->mRect->x;
		}
		else
		{
			//Get the ASCII value of the character
			int ascii = (unsigned char)order.getText()[i];

			//Show the character
			renderChar(order, currentX, currentY, &fontVault[order.getName()].mChars[ascii]);

			//Move over the width of the character with one pixel of padding
			currentX += (fontVault[order.getName()].mChars[ascii].w -2) * fontScale * order.getFontSize();
		}
	}
	return true;
}

bool RenderManager::renderChar(RenderOrder order, int x, int y, SDL_Rect* mRect)
{
	//Set rendering space and render to screen
	SDL_Rect mQuad = { x, y, mRect->w * fontScale * order.getFontSize(), mRect->h * fontScale * order.getFontSize() };

	SDL_Point* mCenter = NULL;
	SDL_RendererFlip mFlip = SDL_FLIP_NONE;

	SDL_RenderCopyEx(
		mRenderer, 
		fontVault[order.getName()].mTexture, 
		mRect, 
		&mQuad, 
		order.getRotation(), 
		mCenter, 
		mFlip);

	return true;
}


int RenderManager::mountViewport(vpc viewportCode)
{
	return SDL_RenderSetViewport(mRenderer, viewportsList.find(viewportCode)->second.mRect);
}

void RenderManager::close()
{
	/*
	for (std::map<string, Texture>::iterator it = textureVault.begin(); it != textureVault.end(); ++it) {

		it->second.close();
	}
		*/

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	mRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}