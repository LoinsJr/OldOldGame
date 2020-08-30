#pragma once

#include "GameObject.h"

class Block : public GameObject
{
	SDL_Rect srcRect;
public:
	int type;
public:
	Block() {}
	Block(int x, int y, int arg_width, int arg_height,const char * arg_textureID, int arg_type = 1);

	void render();
	void update();
};