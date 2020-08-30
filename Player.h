#pragma once

#include "Character.h"
#include "Bullet.h"

class Player : public Character
{
public:
	Player() {}
	Player(int x, int y, int arg_width, int arg_height, const char* arg_textureID, int arg_maxHP = 10, int speed = 5);
	~Player() {}

	void updateAnimation();
	void update();
};
