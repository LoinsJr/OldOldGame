#include "Enemy.h"
#include "Collision.h"

Enemy::Enemy(int x, int y, int arg_width, int arg_height, const char * arg_textureID, int arg_maxHP, int arg_speed): Character(x, y, arg_width, arg_height, arg_textureID, arg_maxHP, arg_speed)
{
	reaction = 55;
}

void Enemy::CollisionByXAxis()
{
	//COLLISION WITH WALL
	int tmpX = Collision::AABBCollision_with_wall(colRect);
	if (velocity.x() != 0 && tmpX != -1)
	{
		velocity.setY(-20);
		acceleration.setY(1);
	}
	else
	{
		SDL_Rect t;
		colRect.x = dstRect.x - reaction;
		colRect.w = dstRect.w + 2 * reaction;
		//COLLISION WITH BULLET
		bool anticipation = Collision::AABBCollision_with_playerbullet(colRect, false);

		colRect.x += reaction;
		colRect.w -= 2 * reaction;
		bool hitByBullet = Collision::AABBCollision_with_playerbullet(colRect);
		if (acceleration.y() == 0 && anticipation && !hitByBullet)
		{
			velocity.setY(-20);
		}
		else if (hitByBullet)
		{
			damaged(2);
		}
	}
}

void Enemy::updateAnimation()
{
	//ANIMATION
	if (curAnim.getType() != action + way)
	{
		if (attacking)
		{
			curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 300, 3, false);
		}
		else if (velocity.x() != 0)
		{
			curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 200);
		}
		else
		{
			curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 1200, 1);
		}
	}
	//ANIMATION UPDATE
	if (!curAnim.update() && attacking)
	{
		if (Collision::AABBCollision(colRect, Game::Instance().player->dstRect))
			Game::Instance().player->damaged(2);

		attacking = false;
		action = STANDING;
		curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 1200);
	}
}


void Enemy::update(Character * instance)
{
	if (curHP <= 0)
	{
		visible = false;
		existing = false;
	}
	else 
	{
		//COLLISION WITH PLAYER && RUNNING FOR PLAYER
		if (!attacking && existing && Game::Instance().player != nullptr)
		{
			if (Collision::AABBCollision(dstRect, Game::Instance().player->dstRect))
			{
				attacking = true;
				action = ATTACK;
			}
			else if (Game::Instance().player->x() > dstRect.x + dstRect.w)
			{
				if (!attacking)
					velocity.setX(2);
				way = RIGHT;
			}
			else if (Game::Instance().player->x() + Game::Instance().player->dstRect.w < dstRect.x)
			{
				if (!attacking)
					velocity.setX(-2);
				way = LEFT;
			}
			else
			{
				velocity.setX(0);
			}
		}
		else velocity.setX(0);
		Character::update(this);
	}
}

void Enemy::render()
{
	curAnim.render(dstRect);
}


