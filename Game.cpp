#include "Game.h"



bool Game::init(const char * title, int x, int y, int width, int height)
{
	m_Running = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Initialised successfully!" << std::endl;

		window = SDL_CreateWindow(title, x, y, width, height, 0);
		if (window != nullptr)
		{
			std::cout << "Window is created!" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);

			Uint8 r = 0, g = 0, b = 0, a = 255;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		else
		{
			std::cout << "Window creation failed!" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Game::Initialisation failed!" << std::endl;
		return false;
	}
	m_Running = true;
	Game::camera = { 0, 0, 1200, 700 };
	//LOADS
	TextureManager::Instance().load("player", "Hero32.png");
	TextureManager::Instance().load("block", "Block.png");
	TextureManager::Instance().load("bullet", "Bullet.png");
	TextureManager::Instance().load("enemy", "Hero4_96_96.png");
	background = TextureManager::Instance().load("background", "Background.png");
	//CREATING OBJECTS
	level = new Level("lvl1.txt");
	player = new Player(20, 20, 92, 152, "player");
	
	std::cout << "Level created" << std::endl;
	
	return true;
}

void Game::update()
{
	SDL_Event event;
	//std::cout << "Updating" << std::endl;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: SDL_Quit(); break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				pressedButtons["w"] = true; break;
			case SDLK_a:
				pressedButtons["a"] = true; break;
			case SDLK_s:
				pressedButtons["s"] = true; break;
			case SDLK_d:
				pressedButtons["d"] = true; break;
			case SDLK_q:
				pressedButtons["q"] = true; break;
			default: break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				pressedButtons["w"] = false; break;
			case SDLK_a:
				pressedButtons["a"] = false; break;
			case SDLK_s:
				pressedButtons["s"] = false; break;
			case SDLK_d:
				pressedButtons["d"] = false; break;
			case SDLK_q:
				pressedButtons["q"] = false; break;
			default: break;
			}
		case NULL: break;
		}
	}

	
	if (player != nullptr)
	{
		player->update();
		//CAMERA
		camera.x = player->x() - 600;
		if (camera.x < 0)
			camera.x = 0;
		//DELETE PLAYER
		if (!player->isExisting())
		{
			delete player;
			player = nullptr;
		}
	}
		
	level->update();
	
	GameObject * tmp_bullet = nullptr;
	for (uint16_t i = 0; i < playerBullets.size();)
	{
		playerBullets[i]->update();
		if (!playerBullets[i]->isExisting())
		{
			tmp_bullet = playerBullets[i];
			playerBullets.erase(playerBullets.begin() + i);
			delete tmp_bullet;
		}
		else ++i;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, background, NULL, NULL);
	
	if (player != nullptr)
		player->render();

	level->render();

	for (int i = 0; i < Game::Instance().playerBullets.size(); ++i)
		if (Game::Instance().playerBullets[i]->isVisible())
			Game::Instance().playerBullets[i]->render();
	SDL_RenderPresent(renderer);
}
