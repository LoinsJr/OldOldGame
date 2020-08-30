#pragma once

#include "include/SDL.h"
#include "include/SDL_image.h"
#include <unordered_map>
#include <iostream>


class TextureManager
{
	TextureManager() {}
	~TextureManager() {}

	std::unordered_map<const char*, SDL_Texture*> textures;
public:
	static TextureManager & Instance()
	{
		static TextureManager m_TextureManager;
		return m_TextureManager;
	}

	SDL_Texture* load(const char* id, const char* fileName = "");
	SDL_Texture* getTexture(const char* id);
	void draw(const char* id, SDL_Rect& srcRect, SDL_Rect& dstRect, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
};