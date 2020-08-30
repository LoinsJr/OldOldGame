#include <vector>
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
	if (!Game::Instance().init("Game", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1200, 700))
	{
		return 100001;
	}
	else
	{
		Uint32 nextTick = SDL_GetTicks();
		const int TICKS_PER_SECOND = 50;
		const int TIME_PER_TICK = 1000 / TICKS_PER_SECOND;
		const int MAX_FRAMESKIP = 10;
		int loops;
		while (Game::Instance().running())
		{
			loops = 0;
			while (SDL_GetTicks() > nextTick && loops < MAX_FRAMESKIP)
			{
				nextTick += TIME_PER_TICK;
				++loops;
				Game::Instance().update();
			}
			Game::Instance().render();
		}
	}
	return 0;
}