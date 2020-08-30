#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"

Character::Character(int x, int y, int arg_width, int arg_height, const char * arg_textureID, int arg_maxHP, int arg_speed) : GameObject(x, y, arg_width, arg_height, arg_textureID)
{
	colRect.w = dstRect.w - 70;
	colRect.h = dstRect.h;
	attacking = false;
	curHP = maxHP = arg_maxHP;
	speed = arg_speed;
	action = STANDING;
	way = RIGHT;
	curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 1200);
} 

void Character::CollisionByXAxis()
{
	int tmpX = Collision::AABBCollision_with_wall(colRect);
	if (velocity.x() != 0 && tmpX != -1)
	{
		velocity.setX(0);
		acceleration.setX(0);
		colRect.x = tmpX;
		dstRect.x = tmpX - 35;
		//pos.setX(dstRect.x + Game::Instance().camera.x);
	}
}

void Character::CollisionByYAxis()
{
	int tmpY = Collision::AABBCollision_with_floor(colRect);
	if (velocity.y() > 0 && tmpY != -1)
	{
		acceleration.setY(0);
		velocity.setY(0);
		dstRect.y = tmpY - dstRect.h;
		colRect.y = dstRect.y;
		pos.setY(tmpY - dstRect.h);	
	}
	else if (tmpY == -1)
	{
		acceleration.setY(1);
	}
}

void Character::updateAnimation()
{
	curAnim.update();
}

void Character::update(Character * instance)
{
	if (curHP <= 0 && maxHP != 0)
	{
		visible = false;
		existing = false;
	}
	else
	{
		//INTERPOLATION
		colRect.x = dstRect.x + velocity.x() + 35; 
		colRect.y = dstRect.y + velocity.y() + acceleration.x();
		//COLLISION
		if (instance == nullptr)
			CollisionByYAxis();
		else instance->CollisionByYAxis();
		if (instance == nullptr)
			CollisionByXAxis();
		else instance->CollisionByXAxis();
		//UPDATING POSITION
		GameObject::update();
		//CHECKING HP
		if (curHP <= 0)
		{
			destroyObject();
		}
		//UPDATING ANIMATION
		if (instance == nullptr)
			updateAnimation();
		else this->updateAnimation();
	}
}

void Character::render()
{
	curAnim.render(dstRect);
}
