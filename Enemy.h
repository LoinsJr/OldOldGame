#pragma once

#include "Character.h"

class Enemy : public Character
{
	int reaction;
public:
	Enemy() {}
	Enemy(int x, int y, int arg_width, int arg_height, const char * arg_textureID, int arg_maxHP = 10, int arg_speed = 2);
	~Enemy() {}
	
	void CollisionByXAxis();
	void updateAnimation();

	void update(Character * instance = nullptr);
	void render();

	enum { RIGHT, LEFT };
	enum { STANDING = 0, MOVEMENT = 2, ATTACK = 4 };
};