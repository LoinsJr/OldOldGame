#pragma once

#include "SDL.h"
#include <cmath>
#include "Game.h"

class Collision
{
public:
	static bool AABBCollision(SDL_Rect & rect1, SDL_Rect & rect2);
	static int AABBCollision_y(SDL_Rect & rect1, SDL_Rect & rect2);
	static int AABBCollision_x(SDL_Rect & rect1, SDL_Rect & rect2);
	static int AABBCollision_with_floor(SDL_Rect & rect);
	static int AABBCollision_with_wall(SDL_Rect & rect);
	static bool AABBCollision_with_playerbullet(SDL_Rect & rect, bool destroyBullet = true);
};