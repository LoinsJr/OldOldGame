#pragma once

#include "GameObject.h"
#include <functional>

class Character; 

class Character : public GameObject
{
protected:
	Animation curAnim;
	int curHP, maxHP;
	int speed;
	int action, way;
	bool attacking;

	enum {RIGHT, LEFT};
	enum {STANDING = 0, MOVEMENT = 2, ATTACK = 4};
public:
	Character() {}
	Character(int x, int y, int arg_width, int arg_height, const char* arg_textureID, int arg_maxHP = 1, int arg_speed = 0);
	~Character() {}

	void damaged(int dmg) { curHP -= dmg; std::cout << curHP << "/" << maxHP << std::endl; }
	void setHP(int arg_HP) { maxHP = arg_HP; curHP = maxHP; }
	
	virtual void CollisionByXAxis();
	virtual void CollisionByYAxis();
	virtual void updateAnimation();

	virtual void update(Character * instance = nullptr);
	void render();

	int getCurHP() { return curHP; }
	int getMaxHP() { return maxHP; }
	int getSpeed() { return speed; }
	bool isAttacking() { return attacking; }
};
