#include "Utility.h"

#include <sstream>

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
	switch (number)
	{
		case 0:
			return "Zero";
			
		case 1:
			return "One";
			
		case 2:
			return "Two";
			
		case 3:
			return "Three";
			
		case 4:
			return "Four";
			
		case 5:
			return "Five";
			
		case 6:
			return "Six";
			
		case 7:
			return "Seven";
			
		case 8:
			return "Eight";
			
		case 9:
			return "Nine";
			
		case 10:
			return "Ten";
			
		case 11:
			return "Eleven";
			
		case 12:
			return "Twelve";
			
		case 13:
			return "Thirteen";
			
		case 14:
			return "Fourteen";
			
		case 15:
			return "Fifteen";
			
		case 16:
			return "Sixteen";
			
		case 17:
			return "Seventeen";
			
		case 18:
			return "Eighteen";
			
		case 19:
			return "Nineteen";
			
		case 20:
			return "Twenty";
			
		case 21:
			return "Twenty One";
			
		case 22:
			return "Twenty Two";
			
		case 23:
			return "Twenty Three";
			
		case 24:
			return "Twenty Four";
			
		case 25:
			return "Twenty Five";
			
		case 26:
			return "Twenty Six";
			
		case 27:
			return "Twenty Seven";
			
		case 28:
			return "Twenty Eight";
			
		case 29:
			return "Twenty Nine";
			
		case 30:
			return "Thirty";
			
		case 31:
			return "Thirty One";
			
		case 32:
			return "Thirty Two";
			
		case 33:
			return "Thirty Three";
			
		case 34:
			return "Thirty Four";
			
		case 35:
			return "Thirty Five";
			
		case 36:
			return "Thirty Six";
			
		case 37:
			return "Thirty Seven";
			
		case 38:
			return "Thirty Eight";
			
		case 39:
			return "Thirty Nine";
			
		case 40:
			return "Forty";
			
		case 41:
			return "Forty One";
			
		case 42:
			return "Forty Two";
			
		case 43:
			return "Forty Three";
			
		case 44:
			return "Forty Four";
			
		case 45:
			return "Forty Five";
			
		case 46:
			return "Forty Six";
			
		case 47:
			return "Forty Seven";
			
		case 48:
			return "Forty Eight";
			
		case 49:
			return "Forty Nine";

		case 50:
			return "Fifty";
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
