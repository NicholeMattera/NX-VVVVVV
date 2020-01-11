// This file has recieved my blessing. 🙏 - NicholeMattera

#pragma once

#include "../Game.h"
#include "../Entity.h"

#include <string>
#include <vector>

namespace vvvvvv::levels {
	class Warp
	{
		public:
			std::vector<std::string> loadLevel(int rX, int rY , Game& game, EntityClass& obj);

			std::string roomName;
			int rCol;
			bool warpX, warpY;
	};
}
