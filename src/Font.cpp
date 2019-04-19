#include "Font.h"

Font::Font()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPixels = NULL;
	mPitch = 0;

	mNewLine = 0;
	mSpace = 0;
}

bool Font::load(SDL_Renderer* mRenderer, string name)
{
	
	SDL_Surface* tempSurface = IMG_Load(("./Resources/Fonts/" + name + ".png").c_str());
	if (tempSurface == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Error loading font",
			NULL);
		return false;
	}

	SDL_Texture* newTexture = NULL;

	SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat(tempSurface, SDL_PIXELFORMAT_RGBA8888, NULL);
	if (formattedSurface == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Not correct display format",
			NULL);
		return false;
	}

	newTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h);
	if (newTexture == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Cannot create texture (font loading)",
			NULL);
		return false;
	}

	SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);

	//Lock texture for manipulation
	SDL_LockTexture(newTexture, &formattedSurface->clip_rect, &mPixels, &mPitch);

	//Copy loaded/formatted surface pixels
	memcpy(mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);

	//Get image dimensions
	mWidth = formattedSurface->w;
	mHeight = formattedSurface->h;

	//Get pixel data in editable format
	Uint32* pixels = (Uint32*)mPixels;
	int pixelCount = (mPitch / 4) * mHeight;

	//Map colors				
	Uint32 colorKey = SDL_MapRGB(formattedSurface->format, 0x00, 0xFF, 0xFF);
	Uint32 transparent = SDL_MapRGBA(formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00);

	for (int i = 0; i < pixelCount; ++i)
	{
		if (pixels[i] == colorKey)
		{
			pixels[i] = transparent;
		}
	}

	//Unlock texture to update
	SDL_UnlockTexture(newTexture);
	mPixels = NULL;

	SDL_FreeSurface(formattedSurface);
	SDL_FreeSurface(tempSurface);

	mTexture = newTexture;

	//build font
	build();

	return true;
}

bool Font::lockTexture()
{
	if (mPixels != NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Multiple attempt to lock texture (font loading)",
			NULL);
	}
	else
	{
		if (SDL_LockTexture(mTexture, NULL, &mPixels, &mPitch) != 0)
		{
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
				"JamEngine error",
				"Cannot lock texture (font loading)",
				NULL);
			return false;
		}
	}
	return true;
}

bool Font::unlockTexture()
{
	if (mPixels == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Texture not locked (font loading)",
			NULL);
		return true;
	}
	else
	{
		SDL_UnlockTexture(mTexture);
		mPixels = NULL;
		mPitch = 0;
	}

	return true;
}

Uint32 Font::getPixel32(unsigned int x, unsigned int y)
{
	//Convert the pixels to 32 bit
	Uint32 *pixels = (Uint32*)mPixels;

	//Get the pixel requested
	return pixels[(y * (mPitch / 4)) + x];
}

bool Font::build()
{
	if (!lockTexture())
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
			"JamEngine error",
			"Cannot lock texture (font loading)",
			NULL);
		return false;
	}
	else
	{
		//Set the background color
		Uint32 bgColor = getPixel32(0, 0);

		int cellW = mWidth / 16;
		int cellH = mHeight / 16;

		int top = cellH;
		int baseA = cellH;

		int currentChar = 0;

		for (int rows = 0; rows < 16; ++rows)
		{
			for (int cols = 0; cols < 16; ++cols)
			{
				mChars[currentChar].x = cellW * cols;
				mChars[currentChar].y = cellH * rows;

				mChars[currentChar].w = cellW;
				mChars[currentChar].h = cellH;

				for (int pCol = 0; pCol < cellW; ++pCol)
				{
					for (int pRow = 0; pRow < cellH; ++pRow)
					{
						int pX = (cellW * cols) + pCol;
						int pY = (cellH * rows) + pRow;

						//If a no colorkey pixel is found
						if (getPixel32(pX, pY) != bgColor)
						{
							mChars[currentChar].x = pX;

							pCol = cellW;
							pRow = cellH;
						}
					}
				}

				for (int pColW = cellW - 1; pColW >= 0; --pColW)
				{
					for (int pRowW = 0; pRowW < cellH; ++pRowW)
					{
						int pX = (cellW * cols) + pColW;
						int pY = (cellH * rows) + pRowW;

						//If a no colorkey pixel is found
						if (getPixel32(pX, pY) != bgColor)
						{
							mChars[currentChar].w = (pX - mChars[currentChar].x) + 1;

							pColW = -1;
							pRowW = cellH;
						}
					}
				}

				//Find Top
				//Go through pixel rows
				for (int pRow = 0; pRow < cellH; ++pRow)
				{
					//Go through pixel columns
					for (int pCol = 0; pCol < cellW; ++pCol)
					{
						//Get the pixel offsets
						int pX = (cellW * cols) + pCol;
						int pY = (cellH * rows) + pRow;

						//If a non colorkey pixel is found
						if (getPixel32(pX, pY) != bgColor)
						{
							//If new top is found
							if (pRow < top)
							{
								top = pRow;
							}

							//Break the loops
							pCol = cellW;
							pRow = cellH;
						}
					}
				}

				//Find Bottom of A
				if (currentChar == 'A')
				{
					//Go through pixel rows
					for (int pRow = cellH - 1; pRow >= 0; --pRow)
					{
						//Go through pixel columns
						for (int pCol = 0; pCol < cellW; ++pCol)
						{
							//Get the pixel offsets
							int pX = (cellW * cols) + pCol;
							int pY = (cellH * rows) + pRow;

							//If a non colorkey pixel is found
							if (getPixel32(pX, pY) != bgColor)
							{
								//Bottom of a is found
								baseA = pRow;

								//Break the loops
								pCol = cellW;
								pRow = -1;
							}
						}
					}
				}

				//Go to the next character
				++currentChar;
			}
		}

		//Calculate space
		mSpace = cellW / 2;

		//Calculate new line
		mNewLine = baseA - top;

		//Lop off excess top pixels
		for (int i = 0; i < 256; ++i)
		{
			mChars[i].y += top;
			mChars[i].h -= top;
		}

		unlockTexture();
		//mTexture = bitmap;
	}
}