#if defined(__SWITCH__)
    #include <SDL2/SDL.h>
#else
    #include <SDL.h>
#endif
#include "SoundSystem.h"

#include "UtilityClass.h"
#include "Game.h"
#include "Graphics.h"
#include "KeyPoll.h"
#include "titlerender.h"

#include "Tower.h"
#include "WarpClass.h"
#include "Labclass.h"
#include "Finalclass.h"
#include "Map.h"

#include "Screen.h"

#include "Script.h"

#include "Logic.h"

#include "Input.h"
#include "editor.h"
#include "preloader.h"

#include "FileSystemUtils.h"
#include "Network.h"

#include <stdio.h>
#include <string.h>

#if defined(__SWITCH__)
    #include <switch.h>
#endif

scriptclass script;
edentities edentity[3000];

editorclass ed;

int main(int argc, char * argv[])
{
    if (!FILESYSTEM_init(argv[0]))
    {
        return 1;
    }

    SDL_Init(
        SDL_INIT_VIDEO |
        SDL_INIT_AUDIO |
        SDL_INIT_JOYSTICK |
        SDL_INIT_GAMECONTROLLER
    );
    // Switch doesn't have a cursor.
    #if !defined(__SWITCH__)
        SDL_ShowCursor(SDL_DISABLE);
    #endif

    if (argc > 2 && strcmp(argv[1], "-renderer") == 0)
    {
        SDL_SetHintWithPriority(SDL_HINT_RENDER_DRIVER, argv[2], SDL_HINT_OVERRIDE);
    }

    // Switch doesn't have Steam.
    #if !defined(__SWITCH__)
        NETWORK_init();
    #endif

    Screen gameScreen;

	printf("\t\t\n");
	printf("\t\t\n");
	printf("\t\t       VVVVVV\n");
	printf("\t\t\n");
	printf("\t\t\n");
	printf("\t\t  8888888888888888  \n");
	printf("\t\t88888888888888888888\n");
	printf("\t\t888888    8888    88\n");
	printf("\t\t888888    8888    88\n");
	printf("\t\t88888888888888888888\n");
	printf("\t\t88888888888888888888\n");
	printf("\t\t888888            88\n");
	printf("\t\t88888888        8888\n");
	printf("\t\t  8888888888888888  \n");
	printf("\t\t      88888888      \n");
	printf("\t\t  8888888888888888  \n");
	printf("\t\t88888888888888888888\n");
	printf("\t\t88888888888888888888\n");
	printf("\t\t88888888888888888888\n");
	printf("\t\t8888  88888888  8888\n");
	printf("\t\t8888  88888888  8888\n");
	printf("\t\t    888888888888    \n");
	printf("\t\t    8888    8888    \n");
	printf("\t\t  888888    888888  \n");
	printf("\t\t  888888    888888  \n");
	printf("\t\t  888888    888888  \n");
	printf("\t\t\n");
	printf("\t\t\n");

    UtilityClass help;
    Graphics graphics;
    musicclass music;
    Game game;
    game.infocus = true;

    graphics.MakeTileArray();
    graphics.MakeSpriteArray();
    graphics.maketelearray();

    graphics.images.push_back(graphics.grphx.im_image0);
    graphics.images.push_back(graphics.grphx.im_image1);
    graphics.images.push_back(graphics.grphx.im_image2);
    graphics.images.push_back(graphics.grphx.im_image3);
    graphics.images.push_back(graphics.grphx.im_image4);
    graphics.images.push_back(graphics.grphx.im_image5);
    graphics.images.push_back(graphics.grphx.im_image6);

    graphics.images.push_back(graphics.grphx.im_image7);
    graphics.images.push_back(graphics.grphx.im_image8);
    graphics.images.push_back(graphics.grphx.im_image9);
    graphics.images.push_back(graphics.grphx.im_image10);
    graphics.images.push_back(graphics.grphx.im_image11);
    graphics.images.push_back(graphics.grphx.im_image12);

    const SDL_PixelFormat* fmt = gameScreen.GetFormat();
    graphics.backBuffer = SDL_CreateRGBSurface(SDL_SWSURFACE ,320 ,240 ,32,fmt->Rmask,fmt->Gmask,fmt->Bmask,fmt->Amask ) ;
    SDL_SetSurfaceBlendMode(graphics.backBuffer, SDL_BLENDMODE_NONE);
    graphics.Makebfont();

    graphics.forgroundBuffer =  SDL_CreateRGBSurface(SDL_SWSURFACE ,320 ,240 ,fmt->BitsPerPixel,fmt->Rmask,fmt->Gmask,fmt->Bmask,fmt->Amask  );
    SDL_SetSurfaceBlendMode(graphics.forgroundBuffer, SDL_BLENDMODE_NONE);

    graphics.screenbuffer = &gameScreen;

    graphics.menubuffer = SDL_CreateRGBSurface(SDL_SWSURFACE ,320 ,240 ,fmt->BitsPerPixel,fmt->Rmask,fmt->Gmask,fmt->Bmask,fmt->Amask );
    SDL_SetSurfaceBlendMode(graphics.menubuffer, SDL_BLENDMODE_NONE);

    graphics.towerbuffer =  SDL_CreateRGBSurface(SDL_SWSURFACE ,320 ,240 ,fmt->BitsPerPixel,fmt->Rmask,fmt->Gmask,fmt->Bmask,fmt->Amask  );
    SDL_SetSurfaceBlendMode(graphics.towerbuffer, SDL_BLENDMODE_NONE);

	graphics.tempBuffer = SDL_CreateRGBSurface(SDL_SWSURFACE ,320 ,240 ,fmt->BitsPerPixel,fmt->Rmask,fmt->Gmask,fmt->Bmask,fmt->Amask  );
    SDL_SetSurfaceBlendMode(graphics.tempBuffer, SDL_BLENDMODE_NONE);

    game.gamestate = PRELOADER;

    game.menustart = false;
    game.mainmenu = 0;

    KeyPoll key;
    mapclass map;

    map.ypos = (700 - 29) * 8;
    map.bypos = map.ypos / 2;

    game.loadstats(map, graphics);

    if (game.usingmmmmmm == 0) music.usingmmmmmm = false;
    if (game.usingmmmmmm == 1) music.usingmmmmmm = true;
    if (game.slowdown == 0) game.slowdown = 30;

    switch (game.slowdown){
        case 30:
            game.gameframerate = 34;
            break;

        case 24:
            game.gameframerate = 41;
            break;

        case 18:
            game.gameframerate = 55;
            break;

        case 12:
            game.gameframerate = 83;
            break;
        
        default:
            game.gameframerate = 34;
            break;
    }

    // Switch doesn't have Steam.
    #if !defined(__SWITCH__)
        //Check to see if you've already unlocked some achievements here from before the update
        if (game.swnbestrank > 0)
        {
            if (game.swnbestrank >= 1) NETWORK_unlockAchievement("vvvvvvsupgrav5");
            if (game.swnbestrank >= 2) NETWORK_unlockAchievement("vvvvvvsupgrav10");
            if (game.swnbestrank >= 3) NETWORK_unlockAchievement("vvvvvvsupgrav15");
            if (game.swnbestrank >= 4) NETWORK_unlockAchievement("vvvvvvsupgrav20");
            if (game.swnbestrank >= 5) NETWORK_unlockAchievement("vvvvvvsupgrav30");
            if (game.swnbestrank >= 6) NETWORK_unlockAchievement("vvvvvvsupgrav60");
        }

        if (game.unlock[5]) NETWORK_unlockAchievement("vvvvvvgamecomplete");
        if (game.unlock[19]) NETWORK_unlockAchievement("vvvvvvgamecompleteflip");
        if (game.unlock[20]) NETWORK_unlockAchievement("vvvvvvmaster");

        if (game.bestgamedeaths > -1) {
            if (game.bestgamedeaths <= 500) NETWORK_unlockAchievement("vvvvvvcomplete500");
            if (game.bestgamedeaths <= 250) NETWORK_unlockAchievement("vvvvvvcomplete250");
            if (game.bestgamedeaths <= 100) NETWORK_unlockAchievement("vvvvvvcomplete100");
            if (game.bestgamedeaths <= 50) NETWORK_unlockAchievement("vvvvvvcomplete50");
        }

        if (game.bestrank[0] >= 3) NETWORK_unlockAchievement("vvvvvvtimetrial_station1_fixed");
        if (game.bestrank[1] >= 3) NETWORK_unlockAchievement("vvvvvvtimetrial_lab_fixed");
        if (game.bestrank[2] >= 3) NETWORK_unlockAchievement("vvvvvvtimetrial_tower_fixed");
        if (game.bestrank[3] >= 3) NETWORK_unlockAchievement("vvvvvvtimetrial_station2_fixed");
        if (game.bestrank[4] >= 3) NETWORK_unlockAchievement("vvvvvvtimetrial_warp_fixed");
        if (game.bestrank[5] >= 3) NETWORK_unlockAchievement("vvvvvvtimetrial_final_fixed");
    #endif

    entityclass obj;
    obj.init();

    volatile Uint32 time, timePrev = 0;
    game.infocus = true;
    key.isActive = true;
    
    #if defined(__SWITCH__)
        while(appletMainLoop())
    #else
        while(!key.quitProgram)
    #endif
    {
        time = SDL_GetTicks();

        // Update network per frame.
        NETWORK_update();

        //framerate limit to 30
        Uint32 timetaken = time - timePrev;

        if (game.gamestate == EDITORMODE)
		{
            if (timetaken < 24)
            {
                volatile Uint32 delay = 24 - timetaken;
                SDL_Delay( delay );
                time = SDL_GetTicks();
            }
            timePrev = time;
        }
        else
        {
            if (timetaken < game.gameframerate)
            {
                volatile Uint32 delay = game.gameframerate - timetaken;
                SDL_Delay( delay );
                time = SDL_GetTicks();
            }
            timePrev = time;
        }

        key.Poll();
        // Switch stays in fullscreen mode.
        #if !defined(__SWITCH__)
            if (key.toggleFullscreen)
            {
                if (!gameScreen.isWindowed)
                {
                    SDL_ShowCursor(SDL_DISABLE);
                    SDL_ShowCursor(SDL_ENABLE);
                }
                else
                {
                    SDL_ShowCursor(SDL_ENABLE);
                }

                if (game.gamestate == EDITORMODE)
                {
                    SDL_ShowCursor(SDL_ENABLE);
                }

                gameScreen.toggleFullScreen();
                game.fullscreen = !game.fullscreen;
                key.toggleFullscreen = false;

                key.keymap.clear(); //we lost the input due to a new window.
                game.press_left = false;
                game.press_right = false;
                game.press_action = true;
                game.press_map = false;

                printf("Error: failed: %s\n", SDL_GetError());
            }
        #endif

        // Switch is always in focus.
        #if defined(__SWITCH__)
            game.infocus = true;
        #else
            game.infocus = key.isActive;

            if (!game.infocus)
            {
                if (game.getGlobalSoundVol() > 0)
                {
                    game.setGlobalSoundVol(0);
                }
                FillRect(graphics.backBuffer, 0x00000000);
                graphics.bprint(5, 110, "Game paused", 196 - help.glow, 255 - help.glow, 196 - help.glow, true);
                graphics.bprint(5, 120, "[click to resume]", 196 - help.glow, 255 - help.glow, 196 - help.glow, true);
                graphics.bprint(5, 230, "Press M to mute in game", 164 - help.glow, 196 - help.glow, 164 - help.glow, true);
                graphics.render();
                //We are minimised, so lets put a bit of a delay to save CPU
                SDL_Delay(100);
            }
            else
            {
        #endif

        switch (game.gamestate)
        {
            case PRELOADER:
                //Render
                preloaderrender(graphics, game, help);
                break;

            case EDITORMODE:
                graphics.flipmode = false;
                //Input
                editorinput(key, graphics, game, map, obj, help, music);
                //Render
                editorrender(key, graphics, game, map, obj, help);
                //Logic
                editorlogic(key, graphics, game, obj, music, map, help);
                break;

            case TITLEMODE:
                //Input
                titleinput(key, graphics, map, game, obj, help, music);
                //Render
                titlerender(graphics, map, game, obj, help, music);
                //Logic
                titlelogic(graphics, game, obj, help, music, map);
                break;

            case GAMEMODE:
                if (map.towermode)
                {
                    //Input
                    gameinput(key, graphics, game, map, obj, help, music);
                    //Render
                    towerrender(graphics, game, map, obj, help);
                    //Logic
                    towerlogic(graphics, game, obj, music, map, help);
                }
                else
                {
                    if (script.running)
                    {
                        script.run(key, graphics, game, map, obj, help, music);
                    }

                    //Input
                    gameinput(key, graphics, game, map, obj, help, music);
                    //Render
                    gamerender(graphics,map, game, obj, help);
                    //Logic
                    gamelogic(graphics, game, obj, music, map,  help);
                }
                break;

            case MAPMODE:
                //Input
                mapinput(key, graphics, game, map, obj, help, music);
                //Render
                maprender(graphics, game, map, obj, help);
                //Logic
                maplogic(graphics, game, obj ,music , map, help );
                break;

            case TELEPORTERMODE:
                //Input
                if(game.useteleporter)
                {
                    teleporterinput(key, graphics, game, map, obj, help, music);
                }
                else
                {
                    if (script.running)
                    {
                        script.run(key, graphics, game, map, obj, help, music);
                    }

                    gameinput(key, graphics, game, map, obj, help, music);
                }
                //Render
                teleporterrender(graphics, game, map, obj, help);
                //Logic
                maplogic(graphics, game, obj, music, map, help);
                break;

            case GAMECOMPLETE:
                //Input
                gamecompleteinput(key, graphics, game, map, obj, help, music);
                //Render
                gamecompleterender(graphics, game, obj, help, map);
                //Logic
                gamecompletelogic(graphics, game, obj, music, map, help);
                break;

            case GAMECOMPLETE2:
                //Input
                gamecompleteinput2(key, graphics, game, map, obj, help, music);
                //Render
                gamecompleterender2(graphics, game, obj, help);
                //Logic
                gamecompletelogic2(graphics, game, obj, music, map, help);
                break;

            case CLICKTOSTART:
                help.updateglow();
                break;

            default:
                break;
        }

        #if !defined(__SWITCH__)
            }
        #endif

        if (game.savemystats)
        {
            game.savemystats = false;
            game.savestats(map, graphics);
        }

        // Switch doesn't have a keyboard or a way to mute in game, or have the window reset.
        #if !defined(__SWITCH__)
            //Mute button
            if (key.isDown(KEYBOARD_m) && game.mutebutton <= 0 && !ed.textentry)
            {
                game.mutebutton = 8;
                if (game.muted)
                {
                    game.muted = false;
                }
                else
                {
                    game.muted = true;
                }
            }

            if (game.mutebutton > 0)
            {
                game.mutebutton--;
            }

            if (game.muted)
            {
                game.globalsound = 0;
                Mix_VolumeMusic(0) ;
                Mix_Volume(-1,0);
            }

            if (!game.muted && game.globalsound == 0)
            {
                game.globalsound = 1;
                Mix_VolumeMusic(MIX_MAX_VOLUME) ;
                Mix_Volume(-1,MIX_MAX_VOLUME);
            }

            if (key.resetWindow)
            {
                key.resetWindow = false;
                gameScreen.ResizeScreen(-1, -1);
            }
        #endif

        music.processmusic();
        graphics.processfade();
        game.gameclock();
        gameScreen.FlipScreen();
    }

    //Quit SDL
    NETWORK_shutdown();
    SDL_Quit();
    FILESYSTEM_deinit();

    return 0;
}
