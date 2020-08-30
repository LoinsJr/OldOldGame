#include "Block.h"


Block::Block(int x, int y, int arg_width, int arg_height, const char * arg_textureID, int arg_type) : GameObject(x, y, arg_width, arg_height, arg_textureID)
{
	if (arg_type % 10 == 0)
	{
		srcRect.x = arg_width - 20;
		srcRect.y = arg_type / 10 - 1;
	}
	else
	{
		srcRect.x = 20 * (arg_type % 10 - 1);
		srcRect.y = arg_type / 10;
	}
	srcRect.w = 40;
	srcRect.h = 40;

	colRect.w = 40;
	colRect.h = 40;
	type = arg_type;
}

void Block::render()
{
	TextureManager::Instance().draw(textureID, srcRect, dstRect);
}

void Block::update()
{
	colRect.x = dstRect.x;
	colRect.y = dstRect.y;
	GameObject::update();
}
