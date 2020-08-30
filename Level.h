#pragma once
#include <vector>
#include <fstream>
#include "Block.h"
#include "Character.h"

class Level
{
	std::vector<std::vector<int>> map;
public:
	std::vector<Block *> blocks;
	std::vector<Character *> enemies;
public:
	Level(const char * fileName);
	void render();
	void update();
};