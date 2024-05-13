#include "game.h"
#include "configuration.h"

int main(int argc, char* argv[])
{
	game Game(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);
	Game.gameLoop();
	return 0;
}