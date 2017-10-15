#include "../include/submenu.hpp"
#include "../include/tabmenu.hpp"
#include "../include/obj.hpp"

Tabmenu *Submenu::tabmenus[4] = {0, 0, 0, 0};
Tabmenu *Submenu::oldmenus[4] = {0, 0, 0, 0};
Tabmenu *Submenu::tabselect = 0;

Submenu::Submenu(const char *t, const char *a, int x, int y, int w, int h)
{
  obj = new GameObject(0, title = t, a, width = w, height = h);
}

Submenu::~Submenu()
{
  delete obj;

  for (int i = 0; i < 4; i++) {
    if (Submenu::tabmenus[i]) {
      delete Submenu::oldmenus[i];
    }
  }
}

void
Submenu::update()
{

  obj->update();

  for (int i = 0; i < 4; i++) {
    if (Submenu::tabmenus[i])
      Submenu::tabmenus[i]->update();
  }
}

void
Submenu::render()
{
  SDL_SetRenderDrawColor(Game::renderer, 70, 70, 70, 255);
  SDL_Rect rect = { .x = 190, .y = 575, .w = 605, .h = 120 };
  SDL_RenderFillRect(Game::renderer, &rect);
  SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

  obj->render();

  for (int i = 0; i < 4; i++) {
    if (Submenu::tabmenus[i])
      Submenu::tabmenus[i]->render();
  }
}

void
Submenu::clear()
{
  for (int i = 0; i < 4; i++) {
    if (Submenu::tabmenus[i]) {
      delete Submenu::oldmenus[i];
      Submenu::oldmenus[i] = Submenu::tabmenus[i];
    }
  }
}

void
Submenu::handle(SDL_Event event)
{
  clear();
  std::cout << title << std::endl;
}

void
Stats::handle(SDL_Event event)
{
  Submenu::handle(event);
  Submenu::tabmenus[0] = 0;
  Submenu::tabmenus[1] = 0;
  Submenu::tabmenus[2] = 0;
  Submenu::tabmenus[3] = 0;
}

void
Market::handle(SDL_Event event)
{
  Submenu::handle(event);
  Submenu::tabmenus[0] = new NewBus(200, 555, 50, 25);
  Submenu::tabmenus[1] = 0;
  Submenu::tabmenus[2] = 0;
  Submenu::tabmenus[3] = 0;
}

void
Planer::handle(SDL_Event event)
{
  Submenu::handle(event);
  Submenu::tabmenus[0] = 0;
  Submenu::tabmenus[1] = 0;
  Submenu::tabmenus[2] = 0;
  Submenu::tabmenus[3] = 0;
}

void
Construction::handle(SDL_Event event)
{
  Submenu::handle(event);
  Submenu::tabmenus[0] = 0;
  Submenu::tabmenus[1] = 0;
  Submenu::tabmenus[2] = 0;
  Submenu::tabmenus[3] = 0;
}

void
Overview::handle(SDL_Event event)
{
  Submenu::handle(event);
  Submenu::tabmenus[0] = 0;
  Submenu::tabmenus[1] = 0;
  Submenu::tabmenus[2] = 0;
  Submenu::tabmenus[3] = 0;
}

void
Management::handle(SDL_Event event)
{
  Submenu::handle(event);
  Submenu::tabmenus[0] = 0;
  Submenu::tabmenus[1] = 0;
  Submenu::tabmenus[2] = 0;
  Submenu::tabmenus[3] = 0;
}
