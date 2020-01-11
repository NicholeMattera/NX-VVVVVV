// This file has recieved my blessing. 🙏 - NicholeMattera

#include "Preloader.h"

#include "../Enums.h"
#include "../Utility.h"

#define LOADING_BAR_X 0
#define LOADING_BAR_Y(index, offset) (index * 16) - offset
#define LOADING_BAR_W 320
#define LOADING_BAR_H 15

#define FRONT_RECT_X 30
#define FRONT_RECT_Y 20
#define FRONT_RECT_W 260
#define FRONT_RECT_H 200
#define FRONT_RECT_COLOR dwgfx.getBGR(0x3E, 0x31, 0xA2)

#define LOADING_TEXT_X(number_of_chars) 282 - (number_of_chars * 8)
#define LOADING_TEXT_Y 204
#define LOADING_TEXT_COLOR_R 124
#define LOADING_TEXT_COLOR_G 112
#define LOADING_TEXT_COLOR_B 218

namespace vvvvvv::states {
	void Preloader::render(Graphics& dwgfx, Game& game)
	{
		if (fakePercentage < 100) {
			fakePercentage++;

    		offset = (offset + 4 + int(fRandom() * 5.0f)) % 32;

			colorTimer--;
			if (colorTimer <= 0)
			{
				currentColor = (currentColor + int(fRandom() * 5.0f)) % 6;
				colorTimer = 8;
			}

    		switch(currentColor)
			{
				case 0:
					lightColor = dwgfx.RGBflip(0xBF, 0x59, 0x6F);
					darkColor = dwgfx.RGBflip(0x88, 0x3E, 0x53);
					break;

				case 1:
					lightColor = dwgfx.RGBflip(0x6C, 0xBC, 0x5C);
					darkColor = dwgfx.RGBflip(0x50, 0x86, 0x40);
					break;

				case 2:
					lightColor = dwgfx.RGBflip(0x5D, 0x57, 0xAA);
					darkColor = dwgfx.RGBflip(0x2F, 0x2F, 0x6C);
					break;

				case 3:
					lightColor = dwgfx.RGBflip(0xB7, 0xBA, 0x5E);
					darkColor = dwgfx.RGBflip(0x84, 0x83, 0x42);
					break;

				case 4:
					lightColor = dwgfx.RGBflip(0x57, 0x90, 0xAA);
					darkColor = dwgfx.RGBflip(0x2F, 0x5B, 0x6C);
					break;

				case 5:
					lightColor = dwgfx.RGBflip(0x90, 0x61, 0xB1);
					darkColor = dwgfx.RGBflip(0x58, 0x3D, 0x71);
					break;

				default:
					lightColor = dwgfx.RGBflip(0x00, 0x00, 0x00);
					darkColor = dwgfx.RGBflip(0x08, 0x00, 0x00);
					break;
    		}

    		for (int i = 0; i < 18; i++)
			{
				if (i % 2 == 0) 
				{
					FillRect(
						dwgfx.backBuffer,
						LOADING_BAR_X,
						LOADING_BAR_Y(i, offset),
						LOADING_BAR_W,
						LOADING_BAR_H,
						lightColor
					);
				}
				else
				{
					FillRect(
						dwgfx.backBuffer,
						LOADING_BAR_X,
						LOADING_BAR_Y(i, offset),
						LOADING_BAR_W,
						LOADING_BAR_H,
						darkColor
					);
				}
    		}

    		FillRect(
				dwgfx.backBuffer,
				FRONT_RECT_X,
				FRONT_RECT_Y,
				FRONT_RECT_W,
				FRONT_RECT_H,
				FRONT_RECT_COLOR
			);

			if (fakePercentage == 100)
			{
				dwgfx.Print(
					LOADING_TEXT_X(15),
					LOADING_TEXT_Y,
					"LOADING... 100%",
					LOADING_TEXT_COLOR_R,
					LOADING_TEXT_COLOR_G,
					LOADING_TEXT_COLOR_B,
					false
				);
			}
			else
			{
				dwgfx.Print(
					LOADING_TEXT_X(14),
					LOADING_TEXT_Y,
					"LOADING... " + vvvvvv::Utility::toString(fakePercentage) + "%",
					LOADING_TEXT_COLOR_R,
					LOADING_TEXT_COLOR_G,
					LOADING_TEXT_COLOR_B,
					false
				);
			}
		}
		else {
			transition--;

			if (transition <= -10)
			{
				game.gamestate = TITLEMODE;
			}
			else if (transition < 5)
			{
				FillRect(dwgfx.backBuffer, 0, 0, 320, 240, dwgfx.getBGR(0,0,0));
			}
			else if (transition < 20)
			{
				FillRect(dwgfx.backBuffer, 0, 0, 320, 240, 0x000000);

				FillRect(
					dwgfx.backBuffer,
					FRONT_RECT_X,
					FRONT_RECT_Y,
					FRONT_RECT_W,
					FRONT_RECT_H,
					FRONT_RECT_COLOR
				);

				dwgfx.Print(
					LOADING_TEXT_X(15),
					LOADING_TEXT_Y,
					"LOADING... 100%",
					LOADING_TEXT_COLOR_R,
					LOADING_TEXT_COLOR_G,
					LOADING_TEXT_COLOR_B,
					false
				);
			}
		}

		if (game.test)
		{
			dwgfx.Print(5, 5, game.teststring, 196, 196, 255 - vvvvvv::Utility::glow, false);
		}

		dwgfx.drawfade();

		if (game.flashlight > 0 && !game.noflashingmode)
		{
			game.flashlight--;
			dwgfx.flashlight();
		}

		if (game.screenshake > 0  && !game.noflashingmode)
		{
			game.screenshake--;
			dwgfx.screenshake();
		}
		else
		{
			dwgfx.render();
		}
	}

	int Preloader::fakePercentage = 0;
	int Preloader::transition = 30;
	bool Preloader::startGame = false;

	int Preloader::darkColor = 0;
	int Preloader::lightColor = 0;
	int Preloader::currentColor = 0;
	int Preloader::colorTimer = 0;
	int Preloader::offset = 0;
}
