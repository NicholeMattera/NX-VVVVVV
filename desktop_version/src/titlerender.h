#pragma once

#include "Graphics.h"
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

void titlerender(Graphics& dwgfx, MapClass& map, Game& game, EntityClass& obj, MusicClass& music);

void towerrender(Graphics& dwgfx, Game& game, MapClass& map, EntityClass& obj);

void gamerender(Graphics& dwgfx, MapClass& map, Game& game, EntityClass& obj);

void maprender(Graphics& dwgfx, Game& game, MapClass& map, EntityClass& obj);

void teleporterrender(Graphics& dwgfx, Game& game, MapClass& map, EntityClass& obj);

void gamecompleterender(Graphics& dwgfx, Game& game, EntityClass& obj, MapClass& map);

void gamecompleterender2(Graphics& dwgfx, Game& game, EntityClass& obj);
