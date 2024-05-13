#pragma once

#include "game.h"

class scoreboard
{
	int id;
	int sc;
	TTF_Font* font;
	SDL_Surface* scoreSurface;
	SDL_Texture* fontTex;
	SDL_Color fontColor;
	SDL_Rect fontDesR;
public:
	scoreboard(int);
	void changeW(int);
	int getID(); 
	void displayScore(int, SDL_Renderer*);
};