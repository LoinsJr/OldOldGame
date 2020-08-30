#include "Bullet.h"
#include <iostream>


Bullet::Bullet(int x, int y, int arg_height, int arg_width, int way, const char * arg_textureID, int arg_velocity): GameObject(x, y, arg_width, arg_height, arg_textureID)
{
	colRect.w = arg_width;
	colRect.h = arg_height;
	curAnim = Animation("bullet", arg_width, arg_height, 0, 100, 1);
	velocity.set(arg_velocity - 2 * arg_velocity * way, 0);
}

void Bullet::update()
{
	GameObject::update();
	curAnim.update();
}

void Bullet::render()
{
	curAnim.render(dstRect);
}

