#include "Animation.h"
#include <iostream>

Animation::Animation(const char* arg_textureID, int width, int height, int column, int arg_animSpeed, int arg_frames, bool arg_looped)
{
	srcRect.w = width;
	srcRect.h = height;
	textureID = arg_textureID;
	srcRect.x = 0;
	srcRect.y = column * height;
	animSpeed = arg_animSpeed;
	frames = arg_frames;
	firstFrameTime = SDL_GetTicks();
	looped = arg_looped;
	lastFrame = 0;
}

bool Animation::update()
{
	srcRect.x = (((SDL_GetTicks() - firstFrameTime) / animSpeed) % frames) * srcRect.w;
	
	if (!looped && lastFrame != 0 && srcRect.x == (frames-1)*srcRect.w)
		return false;

	lastFrame = srcRect.x / srcRect.w;
	return true;
}

void Animation::render(SDL_Rect & dstRect)
{
	TextureManager::Instance().draw(textureID, srcRect, dstRect);
}
