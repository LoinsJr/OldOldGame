#pragma once

#include "GameObject.h"

class Bullet: public GameObject
{
	Animation curAnim;
public:
	Bullet() {}
	Bullet(int x, int y, int arg_width, int arg_height, int way, const char * arg_textureID, int arg_velocity = 7);
	void update();
	void render();
};