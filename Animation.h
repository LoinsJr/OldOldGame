#pragma once

#include "include/SDL.h"
#include "TextureManager.h"

class Animation
{
	int curFrame;
	int frames;
	int firstFrameTime;
	int animSpeed;
	int lastFrame;
	bool looped;
	SDL_Rect srcRect;
	const char * textureID;
	
public:
	Animation() {}
	Animation(const char* arg_textureID, int width, int height, int column, int arg_animSpeed, int arg_frames = 4, bool arg_looped = true);
	bool update();
	void render(SDL_Rect & dstRect);
	int getType() { return srcRect.y / srcRect.h; }
};