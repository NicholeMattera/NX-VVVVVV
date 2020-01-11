#pragma once

#include "Game.h"
#include "Entity.h"

#include <string>
#include <vector>

class FinalClass
{
public:
    std::vector<std::string> loadlevel(int rx, int ry, Game& game, EntityClass& obj);

    std::string roomname;
    int coin, rcol;
    bool warpx, warpy;
};
