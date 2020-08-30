#pragma once

#include <iostream>
#include "Player.h"
#include "Level.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

class Game
{
	Game() {}
	~Game() {}
	Game(Game& arg) = delete;
	Game& operator=(Game& arg) = delete;
private:
	bool m_Running;
	SDL_Texture * background;
public:
	SDL_Window * window;
	SDL_Renderer* renderer;
	std::unordered_map<const char*, bool> pressedButtons;

	Player * player;
	Level * level;
	std::vector<GameObject *> playerBullets;
	
	SDL_Rect camera;

	static Game& Instance()
	{
		static Game m_Game;
		return m_Game;
	}

	bool running() { return m_Running; }

	bool init(const char* title, int x, int y, int width, int height);
	void update();
	void render();
	void clean() {}

	
};