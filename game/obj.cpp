#include "../include/obj.hpp"
#include "../include/texture.hpp"

GameObject::GameObject(unsigned char i, const char *name, const char *asset, int w, int h)
{
  id = i;
  title = name;
  rect.w = w;
  rect.h = h;
  tex = TextureManager::loadTexture(asset);
}

GameObject::~GameObject()
{
  SDL_DestroyTexture(tex);
}

unsigned char
GameObject::getId()
{
  return id;
}

const char *
GameObject::getTitle()
{
  return title;
}

void
GameObject::update()
{

}

void
GameObject::render()
{
//  SDL_RenderCopy(Game::renderer, objTexture, &src, &dest);
}

void
GameObject::render(int x, int y)
{
  rect.x = x;
  rect.y = y - (rect.h - 126);
  TextureManager::draw(tex, rect);
}

void
GameObject::handle(SDL_Event event)
{

}
