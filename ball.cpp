 #include "ball.h"

ball::ball()
{
	pos.x = SCREEN_WIDTH / 2 - BALL_SIZE / 2;
	pos.y = SCREEN_HEIGHT / 2 - BALL_SIZE / 2;

	size = BALL_SIZE;
	speed = BALL_SPEED;

	randVel();

	desR.x = (int)pos.x;
	desR.y = (int)pos.y;
	desR.h = size;
	desR.w = size;
}

void ball::resetPos()
{
	pos.x = SCREEN_WIDTH / 2 - BALL_SIZE / 2;
	pos.y = SCREEN_HEIGHT / 2 - BALL_SIZE / 2;
}

void ball::randVel()
{
	int x = (rand() % 4) + 1;
	/*std::random_device genetrator();
	std::uniform_int_distribution<int> distribution(1, 4);
	
	int x = distribution(genetrator);*/
	switch (x)
	{
		case 1:
			vel.x = 1;
			vel.y = 1;
			break;
		case 2:
			vel.x = -1;
			vel.y = 1;
			break;
		case 3:
			vel.x = 1;
			vel.y = -1;
			break;
		case 4:
			vel.x = -1;
			vel.y = -1;
			break;
		default:
			break;
	}
}

void ball::reset()
{
	resetPos();
	randVel();
}

void ball::update(paddle* leftPaddle, paddle *rightPaddle)
{
	pos.x = pos.x + vel.x * speed;
	pos.y = pos.y + vel.y * speed;
	desR.x = (int)pos.x;
	desR.y = (int)pos.y;

	if (pos.y < 0)
	{
		pos.y = 0;
		vel.y *= -1;
	}
	else if (pos.y + size > SCREEN_HEIGHT)
	{
		pos.y = (float)(SCREEN_HEIGHT - size);
		vel.y *= -1;
	}

	if (pos.x > SCREEN_WIDTH)
	{
		reset();
		leftPaddle->addScore();
	}
	else if (pos.x < size * -1)
	{
		reset(); 
		rightPaddle->addScore();
	}

	collision(leftPaddle);
	collision(rightPaddle);
}

bool ball::collision(paddle* Paddle)
{
	if (pos.x + size >= Paddle->GetPosition().x && pos.x <= Paddle->GetPosition().x + Paddle->GetRect()->w && 
		pos.y + size >= Paddle->GetPosition().y && pos.y <= Paddle->GetPosition().y + Paddle->GetRect()->h )
	{
		vel.x *= -1;
		if (Paddle->getID() == 0) {
			pos.x = Paddle->GetPosition().x + Paddle->GetRect()->w;
		}
		else if (Paddle->getID() == 1) {
			pos.x = Paddle->GetPosition().x - size;
		}
		return true;
	}
	return false;
}

void ball::attachTex(SDL_Renderer* rend)
{
	ballTexture = textureManager::LoadTexture("assets/ball.png", rend);
}

SDL_Rect* ball::GetRect(){return &desR;}
SDL_Texture* ball::getTex(){return ballTexture;}