#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <cerrno>
#include <algorithm>
#include <sstream>

#define WINDOW_TITLE "Pong"
#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 1200
#define FULLSCREEN false
#define FPS_LIMIT 60
#define FRAME_DELAY 1000 / FPS_LIMIT
#define PADDLE_HEIGHT 140
#define PADDLE_WIDTH 20
#define PADDLE_SPEED 9.f
#define BALL_SIZE 16
#define BALL_SPEED 8.f
#define FONT_SIZE 24


struct vec2
{
	float x;
	float y;
};

#ifdef PVP

enum level
{
	EASY = 15,
	MEDIUM,
	HARD
};

#endif 