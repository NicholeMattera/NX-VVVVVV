// This file has recieved my blessing. 🙏 - NicholeMattera

#pragma once

#if defined(__SWITCH__)
    #include <SDL2/SDL.h>
#else
    #include <SDL.h>
#endif
#include <vector>
#include <string>

namespace vvvvvv {
    class Utility
    {
        public:
            static int toInt(std::string string);
            static std::string toString(int _v);
            static std::string toString(SDL_GameControllerButton button);
            static std::string toString(std::vector<SDL_GameControllerButton> buttons);
            static std::vector<std::string> split(const std::string &string, char delimiter);
            static std::string twoDigits(int t);
            static std::string timeString(int frames);
            static std::string toWord(int number);

            static bool intersects(SDL_Rect rect1, SDL_Rect rect2);

            static void updateGlow();

            static int glow;
            static int slowSine;
            static int glowDir;
    };
}
