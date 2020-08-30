#include "Player.h"
//#include <iostream>
#include "Collision.h"
#include "Game.h"


Player::Player(int x, int y, int arg_width, int arg_height, const char * arg_textureID, int arg_maxHP, int arg_speed) : Character(x, y, arg_width, arg_height, arg_textureID, arg_maxHP, arg_speed)
{
	colRect.w = dstRect.w - 70;
}

void Player::updateAnimation()
{
	//ANIMATION
	if (curAnim.getType() != action + way)
	{
		if (attacking)
		{
			curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 100, 5, false);
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
		attacking = false;
		action = STANDING;
		Game::Instance().playerBullets.push_back(new Bullet(pos.x() + 46, pos.y() + 80, 40, 40, way, "bullet"));
		curAnim = Animation(textureID, dstRect.w, dstRect.h, action + way, 1200);
	}

}

void Player::update()
{
	if (curHP <= 0)
	{
		visible = false;
		existing = false;
	}
	else
	{
		//DIRECTION & ACTION
		if (!attacking && Game::Instance().pressedButtons["q"])
		{
			velocity.setX(0);
			action = ATTACK;
			attacking = true;
		}
		if (!attacking)
		{
			if (Game::Instance().pressedButtons["a"])
			{
				velocity.setX(-5);
				way = LEFT;
				action = MOVEMENT;
			}
			else if (Game::Instance().pressedButtons["d"])
			{
				velocity.setX(5);
				way = RIGHT;
				action = MOVEMENT;
			}
			else
			{
				velocity.setX(0);
				action = STANDING;
			}
		}
		//JUMPING & CHECKING IF IS ALREADY JUMPING
		if (Game::Instance().pressedButtons["w"] && acceleration.y() == 0)
		{
			velocity.setY(-22);
			acceleration.setY(1);
			/*if (!attacking)
				action = STANDING;*/
		}
		else if (Game::Instance().pressedButtons["s"])
		{
			velocity.setY(5);
		}
		
		Character::update(this);
	}
}
