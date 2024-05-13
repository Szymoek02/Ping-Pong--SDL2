#include "scoreboard.h"

scoreboard::scoreboard(int id)
{
	sc = 9;
	fontColor = { 255,255,10 };
	font = TTF_OpenFont("mozart.ttf", 48);
	if (id == 0)
	{
		fontDesR.h = 100;
		fontDesR.w = 50;
		fontDesR.x = (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 4) - (fontDesR.w / 2);
		fontDesR.y = 0;
	}
	else
	{
		fontDesR.h = 100;
		fontDesR.w = 50;
		fontDesR.x = (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 4) - (fontDesR.w / 2);
		fontDesR.y = 0;
	}
}

void scoreboard::changeW(int s)
{	
	if (s > sc)
	{
		sc = sc * 10 + 9;
		fontDesR.x -= fontDesR.w / round(log10(sc));
		fontDesR.w += 50;
	}
}

void scoreboard::displayScore(int score, SDL_Renderer* rend)
{
	std::string temp = std::to_string(score);
	const char* c = temp.c_str();
	changeW(score);
	scoreSurface = TTF_RenderText_Solid(font, c, fontColor);
	fontTex = SDL_CreateTextureFromSurface(rend, scoreSurface);
	SDL_FreeSurface(scoreSurface);
	SDL_RenderCopy(rend, fontTex, NULL, &fontDesR);
}

int scoreboard::getID() { return id; }