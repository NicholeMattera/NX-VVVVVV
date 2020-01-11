#ifndef SPACESTATION2_H
#define SPACESTATION2_H

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

#endif /* SPACESTATION2_H */
