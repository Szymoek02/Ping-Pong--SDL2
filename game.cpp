#include "game.h"

game::game(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (!window) 
			std::cerr << "Failed to create window" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer) 
			std::cerr << "Failed to create renderer" << std::endl;

		if (TTF_Init() == -1) 
			std::cerr << "Failed to initalize SDL_ttf" << std::endl;

		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) 
			std::cerr << "Failed to init IMG! SDL Error:" << IMG_GetError() << std::endl;

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	ldr.w = 2;
	ldr.h = SCREEN_HEIGHT;
	ldr.x = SCREEN_WIDTH / 2;
	ldr.y = 1;

	/*if defined player vs player new paddle(0) & new paddle(1)
	otherwise new aiPaddle(0) & paddle(1)*/
	
	Ball = new ball();
	Ball->attachTex(renderer);

	leftPaddle = new paddle(0);
	rightPaddle = new paddle(1);

	leftBoard = new scoreboard(0);
	rightBoard = new scoreboard(1);
}

void game::gameLoop()
{
	while (isRunning)
	{
		frameStart = SDL_GetTicks();

		render();
		handleEvents();
		update();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < FRAME_DELAY) SDL_Delay(FRAME_DELAY - frameTime);
	}

	game::~game();
}

void game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
	
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_ESCAPE]) isRunning = false;

	/*leftPaddle->setDir(0);
	if (keys[SDL_SCANCODE_W]) leftPaddle->setDir(-1);
	if (keys[SDL_SCANCODE_S]) leftPaddle->setDir(1);*/
	leftPaddle->setDir(0);
	/*if (Ball->GetRect()->y ) leftPaddle->setDir(-1);
	if (Ball->GetRect()->y) leftPaddle->setDir(1);*/
	

	rightPaddle->setDir(0);
	if (keys[SDL_SCANCODE_UP]) rightPaddle->setDir(-1);
	if (keys[SDL_SCANCODE_DOWN]) rightPaddle->setDir(1);
}

void game::update()
{
	leftPaddle->update();
	rightPaddle->update();
	Ball->update(leftPaddle, rightPaddle);
}

void game::render()
{
	//background
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderClear(renderer);
	//ball
	SDL_RenderCopy(renderer, Ball->getTex(), NULL, Ball->GetRect());
	//paddles
	SDL_SetRenderDrawColor(renderer, 244, 244, 244, 255);
	SDL_RenderFillRect(renderer, leftPaddle->GetRect());
	SDL_RenderFillRect(renderer, rightPaddle->GetRect());
	SDL_RenderFillRect(renderer, &ldr);
	//scoreboard
	leftBoard->displayScore(leftPaddle->getScore(), renderer);
	rightBoard->displayScore(rightPaddle->getScore(), renderer);
	SDL_RenderPresent(renderer);
}

game::~game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
}