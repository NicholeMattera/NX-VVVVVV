#pragma once

#include "Game.h"
#include "Entity.h"

#include <vector>
#include <string>

class LabClass
{
public:
    std::vector<std::string>  loadlevel(int rx, int ry , Game& game, EntityClass& obj);

    std::string roomname;
    int coin, rcol;
};
