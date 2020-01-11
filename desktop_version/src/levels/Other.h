#pragma once

#include "../Game.h"
#include "../Entity.h"

#include <string>
#include <vector>

namespace vvvvvv::levels
{
	class Other
	{
		public:
            Other();
			std::vector<std::string> loadLevel(int rX, int rY , Game& game, EntityClass& obj);

			std::string roomName;
            int roomTileSet;
            bool roomTextOn;
            int roomTextX;
            int roomTextY;
            int roomTextNumberLines;
            std::vector<std::string> roomText;
	};
}
