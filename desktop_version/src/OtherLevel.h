#pragma once

#include "Game.h"
#include "Entity.h"

#include <string>
#include <vector>

class OtherLevelClass
{
public:
    enum
    {
        BLOCK = 0,
        TRIGGER,
        DAMAGE,
        DIRECTIONAL,
        SAFE,
        ACTIVITY
    };

    OtherLevelClass();
    void addline(std::string t);
    std::vector<std::string> loadlevel(int rx, int ry , Game& game, EntityClass& obj);

    std::string roomname;

    int roomtileset;
    int i;

    // roomtext thing in other level
    bool roomtexton;
    int roomtextx, roomtexty, roomtextnumlines;
    std::vector<std::string> roomtext;
};
