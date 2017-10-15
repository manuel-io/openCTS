#include "../include/tabmenu.hpp"
#include "../include/texture.hpp"

Tabmenu *tabmenus[4] = {0, 0, 0, 0};
Tabmenu *tabselect;

Tabmenu::Tabmenu(const char *t, int x, int y, int w, int h)
{
  dest.x = x;
  dest.y = y;
  bg = TextureManager::loadTexture("assets/menu/tabs.png");
  tex = TextureManager::loadFont(title = t, color);
}

Tabmenu::~Tabmenu()
{
  SDL_DestroyTexture(tex);
  SDL_DestroyTexture(bg);
}

void
Tabmenu::update()
{
}

void
Tabmenu::render()
{
  int x, y;

  SDL_QueryTexture(bg, NULL, NULL, &src.w, &src.h);
  x = dest.x;
  y = dest.y;

  dest.x = 185;
  dest.y = 550;
  dest.w = src.w;
  dest.h = src.h;
  TextureManager::draw(bg, src, dest);

  SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
  dest.x = x;
  dest.y = y;
  dest.w = src.w;
  dest.h = src.h;
  TextureManager::draw(tex, src, dest);
}

void
Tabmenu::handle(SDL_Event event)
{
  std::cout << title << std::endl;
}

void
NewBus::handle(SDL_Event) {

}
