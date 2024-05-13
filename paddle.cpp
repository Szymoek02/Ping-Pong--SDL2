#include "paddle.h"

paddle::paddle(int i)
{
	id = i;
	speed = PADDLE_SPEED;
	
	if (id == 0)
	{
		pos.x = 0;
	}
	else if (id == 1)
	{
		pos.x = (float)(SCREEN_WIDTH - width);
	}

	pos.y = (float)(SCREEN_HEIGHT / 2 - height / 2);
	
	rect.x = (int)pos.x;
	rect.y = (int)pos.y;
	rect.h = height;
	rect.w = width;
}

void paddle::update()
{
	pos.y = pos.y + speed * dir;
	
	if (pos.y < 0)
	{
		pos.y = 0;
	}
	else if (pos.y + height > SCREEN_HEIGHT)
	{
		pos.y = (float)(SCREEN_HEIGHT - height);
	}

	rect.y = (int)pos.y;
}

void paddle::setDir(int d) {dir = d;}
int paddle::getID(){return id;}
void paddle::addScore() { score++; }
int paddle::getScore() { return score; }
SDL_Rect* paddle::GetRect(){return &rect;}
vec2 paddle::GetPosition(){return pos;}