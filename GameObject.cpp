#include "GameObject.h"
#include <iostream>
#include "Game.h"

GameObject::GameObject(int x, int y, int arg_width, int arg_height, const char * arg_textureID)
{
	pos.set(x, y);
	velocity.set(0, 0);
	acceleration.set(0, 0);
	colRect.x = dstRect.x = x;
	colRect.y = dstRect.y = y;
	dstRect.w = arg_width;
	dstRect.h = arg_height;
	textureID = arg_textureID;
	existing = true;
	visible = true; 
	
}

bool GameObject::isVisible()
{
	if (pos.x() + dstRect.w < Game::Instance().camera.x || pos.x() > Game::Instance().camera.x + Game::Instance().camera.w)
	{
		visible = false;
	}
	else visible = true;
	return visible;
}

void GameObject::update()
{
	//UPDATING POSITION
	velocity += acceleration;
	//MAX VELOCITY = width/2
	if (velocity.y() > dstRect.w / 2)
	{
		velocity.setY(dstRect.w / 2);
		//acceleration.setY(0);
	}
	pos += velocity;
	dstRect.x = pos.x() - Game::Instance().camera.x;
	dstRect.y = pos.y();
}
