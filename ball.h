#pragma once

#include "game.h"

class ball
{
public:
	ball();
	~ball();
	void update(class paddle* leftPaddle, class paddle* rightPaddle);
	bool collision(class paddle* Paddle);
	void attachTex(SDL_Renderer* renderer);
	void randVel();
	void resetPos(); 
	void reset();
	SDL_Rect* GetRect();
	SDL_Texture* getTex();
private:
	int size;
	float speed;
	vec2 pos;
	vec2 vel; 
	SDL_Rect srcR, desR;
	SDL_Texture* ballTexture;
};