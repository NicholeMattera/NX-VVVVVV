#pragma once

#if defined(__SWITCH__)
	#include <SDL2/SDL_mixer.h>
#else
	#include <SDL_mixer.h>
#endif

class MusicTrack
{
public:
	MusicTrack(const char* fileName);
	MusicTrack(SDL_RWops *rw);
	Mix_Music *m_music;
	bool m_isValid;
};

class SoundTrack
{
public:
	SoundTrack(const char* fileName);
	Mix_Chunk *sound;
};

class SoundSystem
{
public:
	SoundSystem();
	void playMusic(MusicTrack* music);
};
