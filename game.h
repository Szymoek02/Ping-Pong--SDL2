#pragma once 

#include "configuration.h"
#include "textureManager.h"
#include "paddle.h"
#include "ball.h"
#include "scoreboard.h"
#include "aiPaddle.h"

class game 
{
	int frameStart;
	int frameTime;
	bool isRunning;
	/*TODO: if defined pvp left or right side*/
	class paddle* leftPaddle, *rightPaddle;
	class ball* Ball;
	class scoreboard* leftBoard, *rightBoard;
	class SDL_Window* window;
	class SDL_Rect ldr;
	class SDL_Renderer* renderer;
public:
	game(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	~game();
	void gameLoop();
	void handleEvents();
	void update();
	void render();
};
