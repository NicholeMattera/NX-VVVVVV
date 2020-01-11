#pragma once

#include "../Game.h"
#include "../Entity.h"

#include <string>
#include <vector>

namespace vvvvvv::levels
{
	class Final
	{
		public:
			std::vector<std::string> loadLevel(int rX, int rY , Game& game, EntityClass& obj);

			std::string roomName;
			int roomColor;
			bool warpX, warpY;
	};
}
