#pragma once

#include "Game.h"
#include "Entity.h"

#include <string>
#include <vector>

class WarpClass
{
public:
	std::vector<std::string> loadlevel(int rx, int ry , Game& game, EntityClass& obj);

	std::string roomName;
	int rCol;
	bool warpX, warpY;
};
