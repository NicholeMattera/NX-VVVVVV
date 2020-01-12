// This file has recieved my blessing. 🙏 - NicholeMattera

#include "Utility.h"

#include <sstream>

namespace vvvvvv {
	int Utility::toInt(std::string string)
	{
		return std::stoi(string);
	}

	std::string Utility::toString(int number)
	{
		return std::to_string(number);
	}

	std::string Utility::toString(SDL_GameControllerButton button)
	{
		switch (button)
		{
			case SDL_CONTROLLER_BUTTON_A:
				#if defined(__SWITCH__)
					return "B";
				#else
					return "A";
				#endif

			case SDL_CONTROLLER_BUTTON_B:
				#if defined(__SWITCH__)
					return "A";
				#else
					return "B";
				#endif
			
			case SDL_CONTROLLER_BUTTON_X:
				#if defined(__SWITCH__)
					return "Y";
				#else
					return "X";
				#endif
			
			case SDL_CONTROLLER_BUTTON_Y:
				#if defined(__SWITCH__)
					return "X";
				#else
					return "Y";
				#endif

			case SDL_CONTROLLER_BUTTON_BACK:
				#if defined(__SWITCH__)
					return "-";
				#else
					return "BACK";
				#endif

			case SDL_CONTROLLER_BUTTON_GUIDE:
				return "GUIDE";

			case SDL_CONTROLLER_BUTTON_START:
				#if defined(__SWITCH__)
					return "+";
				#else
					return "START";
				#endif

			case SDL_CONTROLLER_BUTTON_LEFTSTICK:
				#if defined(__SWITCH__)
					return "LS";
				#else
					return "L3";
				#endif

			case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
				#if defined(__SWITCH__)
					return "RS";
				#else
					return "R3";
				#endif

			case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
				#if defined(__SWITCH__)
					return "L";
				#else
					return "LB";
				#endif

			case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
				#if defined(__SWITCH__)
					return "R";
				#else
					return "RB";
				#endif

			default:
				SDL_assert(0 && "Unhandled button!");
				return NULL;
		}
	}

	std::string Utility::toString(std::vector<SDL_GameControllerButton> buttons)
	{
		std::string retval = "";
		for (size_t i = 0; i < buttons.size(); i += 1)
		{
			retval += toString(buttons[i]);
			if ((i + 1) < buttons.size())
			{
				retval += ",";
			}
		}
		return retval;
	}

	std::vector<std::string> Utility::split(const std::string &string, char delimiter)
	{
		std::vector<std::string> elems;
		std::stringstream ss(string);
		std::string item;

		while(std::getline(ss, item, delimiter))
		{
			elems.push_back(item);
		}

		return elems;
	}

	std::string Utility::twoDigits(int number)
	{
		if (number < 10)
		{
			return "0" + toString(number);
		}
		else if (number >= 100)
		{
			return "??";
		}

		return toString(number);
	}

	std::string Utility::timeString(int frames)
	{
		int remainder = frames % 30;
		int seconds = (frames - remainder) / 30;
		
		if (seconds < 60)
		{
			return toString(seconds) + ":" + twoDigits(remainder * 100 / 30);
		}

		int minutes = (seconds - seconds % 60) / 60;
		seconds = seconds % 60;
		return toString(minutes) + ":" + twoDigits(seconds) + ":" + twoDigits(remainder * 100 / 30);
	}

	std::string Utility::toWord(int number)
	{
		const int MAX_NUMBER = 50;
		const char* words[] = {
			"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
			"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
			"Seventeen", "Eighteen", "Nineteen", "Twenty", "Twenty One", "Twenty Two",
			"Twenty Three", "Twenty Four", "Twenty Five", "Twenty Six", "Twenty Seven",
			"Twenty Eight", "Twenty Nine", "Thirty", "Thirty One", "Thirty Two",
			"Thirty Three", "Thirty Four", "Thirty Five", "Thirty Six", "Thirty Seven",
			"Thirty Eight", "Thirty Nine", "Forty Zero", "Forty One", "Forty Two",
			"Forty Three", "Forty Four", "Forty Five", "Forty Six", "Forty Seven",
			"Forty Eight", "Forty Nine", "Fifty"
		};

		if (number <= MAX_NUMBER) {
			return words[number];
		}

		return "Lots";
	}

	bool Utility::intersects(SDL_Rect rect1, SDL_Rect rect2)
	{
		//Calculate the sides of rect 1
		int left1 = rect1.x;
		int right1 = rect1.x + rect1.w;
		int top1 = rect1.y;
		int bottom1 = rect1.y + rect1.h;

		//Calculate the sides of rect B
		int left2 = rect2.x;
		int right2 = rect2.x + rect2.w;
		int top2 = rect2.y;
		int bottom2 = rect2.y + rect2.h;

		return (bottom1 > top2 && top1 < bottom2 && right1 > left2 && left1 < right2);
	}

	void Utility::updateGlow()
	{
		slowSine++;
		if (slowSine >= 64) {
			slowSine = 0;
		}

		if (glowDir == 0) {
			glow += 2;
			if (glow >= 62) {
				glowDir = 1;
			}
		}
		else
		{
			glow -= 2;
			if (glow < 2) {
				glowDir = 0;
			}
		}
	}

	int Utility::glow = 0;
	int Utility::slowSine = 0;
	int Utility::glowDir = 0;
}
