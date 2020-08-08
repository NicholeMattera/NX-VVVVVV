#include "UtilityClass.h"

#include <cctype>
#include <SDL.h>
#include <sstream>

/* Used by UtilityClass::GCString to generate a button list */
const char *GCChar(SDL_GameControllerButton button)
{
	if (button == SDL_CONTROLLER_BUTTON_A)
	{
#if defined(__SWITCH__)
		return "B";
#else
		return "A";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_B)
	{
#if defined(__SWITCH__)
		return "A";
#else
		return "B";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_X)
	{
#if defined(__SWITCH__)
		return "Y";
#else
		return "X";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_Y)
	{
#if defined(__SWITCH__)
		return "X";
#else
		return "Y";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_BACK)
	{
#if defined(__SWITCH__)
		return "-";
#else
		return "BACK";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_GUIDE)
	{
		return "GUIDE";
	}
	else if (button == SDL_CONTROLLER_BUTTON_START)
	{
#if defined(__SWITCH__)
		return "+";
#else
		return "START";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_LEFTSTICK)
	{
#if defined(__SWITCH__)
		return "LS";
#else
		return "L3";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_RIGHTSTICK)
	{
#if defined(__SWITCH__)
		return "R3";
#else
		return "R3";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER)
	{
#if defined(__SWITCH__)
		return "L";
#else
		return "LB";
#endif
	}
	else if (button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)
	{
#if defined(__SWITCH__)
		return "R";
#else
		return "RB";
#endif
	}
	SDL_assert(0 && "Unhandled button!");
	return NULL;
}

int ss_toi( std::string _s )
{
	std::istringstream i(_s);
	int x = 0;
	i >> x;
	return x;
}

std::vector<std::string> split( const std::string &s, char delim, std::vector<std::string> &elems )
{
	std::stringstream ss(s);
	std::string item;
	while(std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split( const std::string &s, char delim )
{
	std::vector<std::string> elems;
	return split(s, delim, elems);
}

UtilityClass::UtilityClass() :
glow(0),
	glowdir(0)
{
	for (size_t i = 0; i < SDL_arraysize(splitseconds); i++)
	{
		splitseconds[i] = (i * 100) / 30;
	}

	slowsine = 0;
}

std::string UtilityClass::String( int _v )
{
	std::ostringstream os;
	os << _v;
	return(os.str());
}

int UtilityClass::Int(const char* str, int fallback /*= 0*/)
{
	if (!is_number(str))
	{
		return fallback;
	}

	return SDL_atoi(str);
}

std::string UtilityClass::GCString(std::vector<SDL_GameControllerButton> buttons)
{
	std::string retval = "";
	for (size_t i = 0; i < buttons.size(); i += 1)
	{
		retval += GCChar(buttons[i]);
		if ((i + 1) < buttons.size())
		{
			retval += ",";
		}
	}
	return retval;
}

std::string UtilityClass::twodigits( int t )
{
	if (t < 10)
	{
		return "0" + String(t);
	}
	if (t >= 100)
	{
		return "??";
	}
	return String(t);
}

std::string UtilityClass::timestring( int t )
{
	//given a time t in frames, return a time in seconds
	std::string tempstring = "";
	int temp = (t - (t % 30)) / 30;
	if (temp < 60)   //less than one minute
	{
		t = t % 30;
		tempstring = String(temp) + ":" + twodigits(splitseconds[t]);
	}
	else
	{
		int temp2 = (temp - (temp % 60)) / 60;
		temp = temp % 60;
		t = t % 30;
		tempstring = String(temp2) + ":" + twodigits(temp) + ":" + twodigits(splitseconds[t]);
	}
	return tempstring;
}

std::string UtilityClass::number( int _t )
{
	static const std::string ones_place[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	static const std::string tens_place[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	static const std::string teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

	if (_t < 0)
	{
		return "???";
	}
	else if (_t > 100)
	{
		return "Lots";
	}
	else if (_t == 0)
	{
		return "Zero";
	}
	else if (_t == 100)
	{
		return "One Hundred";
	}
	else if (_t >= 1 && _t <= 9)
	{
		return ones_place[_t-1];
	}
	else if (_t >= 11 && _t <= 19)
	{
		return teens[_t-11];
	}
	else if (_t % 10 == 0)
	{
		return tens_place[(_t/10)-1];
	}
	else
	{
		return tens_place[(_t/10)-1] + " " + ones_place[(_t%10)-1];
	}
}

bool UtilityClass::intersects( SDL_Rect A, SDL_Rect B )
{
	return (SDL_HasIntersection(&A, &B) == SDL_TRUE);
}

void UtilityClass::updateglow()
{
	slowsine++;
	if (slowsine >= 64) slowsine = 0;

	if (glowdir == 0) {
		glow+=2;
		if (glow >= 62) glowdir = 1;
	}else {
		glow-=2;
		if (glow < 2) glowdir = 0;
	}
}

bool is_number(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!SDL_isdigit(static_cast<unsigned char>(str[i])) && (i != 0 || str[0] != '-'))
		{
			return false;
		}
	}
	return true;
}

bool is_positive_num(const std::string& str, bool hex)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (hex)
		{
			if (!isxdigit(static_cast<unsigned char>(str[i])))
			{
				return false;
			}
		}
		else
		{
			if (!SDL_isdigit(static_cast<unsigned char>(str[i])))
			{
				return false;
			}
		}
	}
	return true;
}

bool endsWith(const std::string& str, const std::string& suffix)
{
	if (str.size() < suffix.size())
	{
		return false;
	}
	return str.compare(
		str.size() - suffix.size(),
		suffix.size(),
		suffix
	) == 0;
}
