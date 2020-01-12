// This file has recieved my blessing. 🙏 - NicholeMattera

#pragma once

#include "../Graphics.h"
#include "../Game.h"
#include "../KeyPoll.h"

namespace vvvvvv::states {
	class Preloader
	{
        public:
            static void input(KeyPoll& key, Game& game);
            static void render(Graphics& dwgfx, Game& game);

        private:
            static int fakePercentage;
            static int transition;
            static bool startGame;
            static int darkColor;
            static int lightColor;
            static int currentColor;
            static int colorTimer;
            static int offset;
    };
}
