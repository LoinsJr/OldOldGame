#include "Level.h"
#include "Game.h"
#include "Collision.h"
#include <iostream>

Level::Level(const char * fileName)
{
	std::ifstream in(fileName);
	int tmp;
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			in >> tmp;
			if (tmp != 0)
			{
				blocks.push_back(new Block(j * 40, i * 40, 40, 40, "block", tmp));
			}	
		}
	}
	in.close();
	enemies.push_back(new Enemy(400, 400, 96, 96, "enemy"));
	//enemies.push_back(new Enemy(800, 400, 96, 96, "enemy"));
}

void Level::render()
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		if (blocks[i]->isVisible())
		{
			blocks[i]->render();
		}	
	}
	for (uint16_t i = 0; i < enemies.size(); ++i)
	{
		if (enemies[i]->isVisible())
			enemies[i]->render();
	}
}

void Level::update()
{
	for (std::vector<Block *>::iterator it = blocks.begin(); it != blocks.end(); ++it)
	{
		if ((*it)->isVisible())
			(*it)->update();
	}

	for (std::vector<Character *>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if ((*it)->isVisible())
			(*it)->update();
	}
}
