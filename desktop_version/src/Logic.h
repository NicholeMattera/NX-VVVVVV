#pragma once

#include "Graphics.h"
#include "Game.h"
#include "Entity.h"
#include "Music.h"
#include "Map.h"

void titlelogic(Graphics& dwgfx, Game& game, EntityClass& obj, MusicClass& music, MapClass& map);

void maplogic(Graphics& dwgfx, Game& game, EntityClass& obj,  MusicClass& music, MapClass& map);

void gamecompletelogic(Graphics& dwgfx, Game& game, EntityClass& obj,  MusicClass& music, MapClass& map);

void gamecompletelogic2(Graphics& dwgfx, Game& game, EntityClass& obj,  MusicClass& music, MapClass& map);

void towerlogic(Graphics& dwgfx, Game& game, EntityClass& obj,  MusicClass& music, MapClass& map);

void gamelogic(Graphics& dwgfx, Game& game, EntityClass& obj,  MusicClass& music, MapClass& map);
