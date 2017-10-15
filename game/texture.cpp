#include "../include/texture.hpp"

SDL_Texture * 
TextureManager::loadTexture(const char *filename)
{
  SDL_Surface *tmpSurface = IMG_Load(filename);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  return tex;
}

SDL_Texture *
TextureManager::loadFont(const char *text, SDL_Color color)
{
  SDL_Surface *tmpSurface = TTF_RenderText_Solid(Game::font, text, color);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  return tex;
}

void
TextureManager::draw(SDL_Texture *tex, SDL_Rect dest)
{
  SDL_Rect src;
  src.x = src.y = 0;
  src.w = dest.w;
  src.h = dest.h;
  SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

void
TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
  SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
