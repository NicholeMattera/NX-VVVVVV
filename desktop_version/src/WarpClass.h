#pragma once

#include "Game.h"
#include "Entity.h"

#include <string>
#include <vector>

class WarpClass
{
public:
	std::vector<std::string> loadLevel(int rX, int rY , Game& game, EntityClass& obj);

	std::string roomName;
	int rCol;
	bool warpX, warpY;
};
