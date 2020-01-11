#pragma once

#include "Graphics.h"
#include "UtilityClass.h"
#include "Maths.h"
#include "Entity.h"
#include "Map.h"
#include "Script.h"

class Stage
{
public:
    int frameRate;
};

extern Stage stage;
extern Stage swfStage;
extern int temp;

void titlerender(Graphics& dwgfx, MapClass& map, Game& game, EntityClass& obj, UtilityClass& help, MusicClass& music);

void towerrender(Graphics& dwgfx, Game& game, MapClass& map, EntityClass& obj, UtilityClass& help);

void gamerender(Graphics& dwgfx, MapClass& map, Game& game, EntityClass& obj, UtilityClass& help);

void maprender(Graphics& dwgfx, Game& game, MapClass& map, EntityClass& obj, UtilityClass& help);

void teleporterrender(Graphics& dwgfx, Game& game, MapClass& map, EntityClass& obj, UtilityClass& help);

void gamecompleterender(Graphics& dwgfx, Game& game, EntityClass& obj, UtilityClass& help, MapClass& map);

void gamecompleterender2(Graphics& dwgfx, Game& game, EntityClass& obj, UtilityClass& help);
