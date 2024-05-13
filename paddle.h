#pragma once

#include "game.h"

class paddle
{
public:
	paddle(int i);
	~paddle();
	int getID();
	void update();
	void setDir(int d);
	void addScore();
	int getScore();
	vec2 GetPosition();
	SDL_Rect* GetRect();
private:
	int id;
	int height = PADDLE_HEIGHT;
	int	width = PADDLE_WIDTH;
	int dir = 0;
	float speed;
	int score = 0;
	vec2 pos;
	SDL_Rect rect;
};