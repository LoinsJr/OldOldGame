#include "TextureManager.h"
#include "Game.h"

SDL_Texture * TextureManager::load(const char * id, const char * fileName)
{
	SDL_Surface* tmpSurface = nullptr;
	SDL_Texture* tmpTexture = nullptr;

	if (textures[id])
	{
		std::cout << "Texture Manager has this texture" << std::endl;
		return textures[id];
	}

	tmpSurface = IMG_Load(fileName);

	if (tmpSurface == nullptr)
	{
		std::cout << "No such file in directory: " << fileName << " (" << id << ")" << std::endl;
		return nullptr;
	}

	tmpTexture = SDL_CreateTextureFromSurface(Game::Instance().renderer, tmpSurface);
	textures[id] = tmpTexture;

	SDL_FreeSurface(tmpSurface);
	std::cout << "SUCCESS: " << fileName << " (" << id << ")" << std::endl;
	return tmpTexture;
}

SDL_Texture * TextureManager::getTexture(const char * id)
{
	return textures[id];
}

void TextureManager::draw(const char * id, SDL_Rect& srcRect, SDL_Rect& dstRect, SDL_RendererFlip flip)
{


	SDL_RenderCopyEx(Game::Instance().renderer, textures[id], &srcRect, &dstRect, NULL, NULL, flip);
}
