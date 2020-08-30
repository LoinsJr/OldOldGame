#pragma once

#include "Vector2D.h"
#include "SDL.h"
#include "Animation.h"
#include "TextureManager.h"

class GameObject;

class GameObject
{
protected:
	bool visible;
	bool existing;
	const char* textureID;
public:
	SDL_Rect dstRect;
	SDL_Rect colRect;
	Vector2D pos;
	Vector2D velocity;
	Vector2D acceleration;
public:
	GameObject() {}
	GameObject(int x, int y, int arg_width, int arg_height, const char* arg_textureID);

	void setPos(int x = 0, int y = 0) { pos.set(x, y); }
	void setVelocity(int x = 0, int y = 0) { velocity.set(x, y); }
	void setAcceleration(int x = 0, int y = 0) { acceleration.set(x, y); }
	void setTexture(const char * arg_textureID) { textureID = arg_textureID; }
	void destroyObject() { visible = false; existing = false; }
	int x() { return pos.x(); }
	int y() { return pos.y(); }
	bool isExisting() { return existing; }
	bool isVisible();

	virtual void update();
	virtual void render() = 0;
	

};