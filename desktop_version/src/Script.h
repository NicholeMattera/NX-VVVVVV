#pragma once

#include <string>
#include <vector>

#include "Enums.h"


class KeyPoll; class Graphics; class Game; class MapClass; class EntityClass; class MusicClass;


class ScriptClass
{
public:


    ScriptClass();

	void load(std::string t);
	void loadother(std::string t);


    void inline add(std::string t)
    {
        commands[scriptlength] = t;
        scriptlength++;
    }

    void clearcustom();

    void tokenize(std::string t);

    void run(KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
             EntityClass& obj, MusicClass& music);

    void resetgametomenu(Graphics& dwgfx, Game& game,MapClass& map,
                         EntityClass& obj, MusicClass& music);

    void startgamemode(int t, KeyPoll& key, Graphics& dwgfx, Game& game, MapClass& map,
                       EntityClass& obj, MusicClass& music);

    void teleport(Graphics& dwgfx, Game& game, MapClass& map,
                  EntityClass& obj, MusicClass& music);

    void hardreset(KeyPoll& key, Graphics& dwgfx, Game& game,MapClass& map,
                   EntityClass& obj, MusicClass& music);

    //Script contents
    std::vector<std::string> commands;
    std::vector<std::string> words;
    std::vector<std::string> txt;
    std::string scriptname;
    int position, scriptlength;
    int looppoint, loopcount;

    int scriptdelay;
    bool running;
    std::string tempword;
    std::string currentletter;

    //Textbox stuff
    int textx;
    int texty;
    int r,g,b;
    int txtnumlines;

    //Misc
    int i, j, k;

    //Custom level stuff
     std::vector <std::string>  customscript;
};
