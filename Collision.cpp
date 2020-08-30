#include "Collision.h"

bool Collision::AABBCollision(SDL_Rect & rect1, SDL_Rect & rect2)
{
	if (abs(rect1.x + rect1.w/2 - rect2.x - rect2.w/2) > rect1.w/2 + rect2.w/2)
		return false;

	if (abs(rect1.y + rect1.h/2 - rect2.y - rect2.h/2) > rect1.h/2 + rect2.h/2)
		return false;

	return true;
}

int Collision::AABBCollision_y(SDL_Rect & rect1, SDL_Rect & rect2)
{
	if (abs(rect1.x + rect1.w / 2 - rect2.x - rect2.w / 2) >= rect1.w / 2 + rect2.w / 2)
		return -1;

	if (abs(rect1.y + rect1.h / 2 - rect2.y - rect2.h / 2) > rect1.h / 2 + rect2.h / 2)
		return -1;

	return rect2.y;
}

int Collision::AABBCollision_x(SDL_Rect & rect1, SDL_Rect & rect2)
{
	if (abs(rect1.x + rect1.w / 2 - rect2.x - rect2.w / 2) > rect1.w / 2 + rect2.w / 2)
		return -1;

	if (abs(rect1.y + rect1.h / 2 - rect2.y - rect2.h / 2) >= rect1.h / 2 + rect2.h / 2)
		return -1;

	if (rect1.x < rect2.x)
		return rect2.x - rect1.w;
	return rect2.x + rect2.w;
}

int Collision::AABBCollision_with_floor(SDL_Rect & rect)
{
	int tmpY = -1;
	for (std::vector<Block *>::iterator it = Game::Instance().level->blocks.begin(); it != Game::Instance().level->blocks.end(); ++it)
	{
		tmpY = AABBCollision_y(rect, (*it)->colRect);
		if ((*it)->isVisible() && tmpY != -1)
		{
			return tmpY;
		}
	}
	return tmpY;
}

int Collision::AABBCollision_with_wall(SDL_Rect & rect)
{
	int tmpX = -1;
	for (std::vector<Block *>::iterator it = Game::Instance().level->blocks.begin(); it != Game::Instance().level->blocks.end(); ++it)
	{
		tmpX = AABBCollision_x(rect, (*it)->colRect);
		if ((*it)->isVisible() && tmpX != -1)
		{
			return tmpX;
		}
	}
	return tmpX;
}

bool Collision::AABBCollision_with_playerbullet(SDL_Rect & rect, bool destroyBullet)
{
	for (uint16_t i = 0; i < Game::Instance().playerBullets.size(); ++i)
	{
		if (AABBCollision(rect, Game::Instance().playerBullets[i]->colRect))
		{
			if (destroyBullet)
				Game::Instance().playerBullets[i]->destroyObject();
			return true;
		}
	}
	return false;
}

