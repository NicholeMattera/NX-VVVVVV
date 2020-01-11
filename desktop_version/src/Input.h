#ifndef INPUT_H
#define INPUT_H

#include "KeyPoll.h"
#include "Graphics.h"
#include "Game.h"
#include "Entity.h"
#include "UtilityClass.h"
#include "Music.h"
#include "Map.h"

void titleinput(KeyPoll& key, Graphics& dwgfx, MapClass& map, Game& game,
                EntityClass& obj, UtilityClass& help, MusicClass& music);

void gameinput(KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
               EntityClass& obj, UtilityClass& help, MusicClass& music);

void mapinput(KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
              EntityClass& obj, UtilityClass& help, MusicClass& music);

void teleporterinput(KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
                     EntityClass& obj, UtilityClass& help, MusicClass& music);

void gamecompleteinput(KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
                       EntityClass& obj, UtilityClass& help, MusicClass& music);

void gamecompleteinput2(KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
                        EntityClass& obj, UtilityClass& help, MusicClass& music);

#endif /* INPUT_H */
