#pragma once

#include "Game.h"
#include "Entity.h"

#include <string>
#include <vector>

class spacestation2class
{
public:
	std::vector<std::string> loadlevel(int rx, int ry, Game& game, EntityClass& obj);
	std::string roomname;
};
