#ifndef TABMENU_H
#define TABMENU_H

#include "game.hpp"

class GameObject;

class Tabmenu {
public:
  Tabmenu(const char *, int, int, int, int);
  virtual ~Tabmenu();

  virtual void handle(SDL_Event);
  void update();
  void render();

private:
  int xpos = 0;
  int ypos = 0;
  int width = 50;
  int height = 50;
  const char *title;

  SDL_Texture *tex, *bg;
  SDL_Color color = { 255, 255, 255 };
  SDL_Rect src = { .x = 0, .y = 0, .w = 50, .h = 25};
  SDL_Rect dest = { .x = 0, .y = 0, .w = 50, .h = 25};
};

#endif /* TABMENU_H */

class NewBus : public Tabmenu {
public:
  NewBus(int x, int y, int w, int h) : Tabmenu("New Bus", x, y, w, h) {};
  ~NewBus() { };
  void handle(SDL_Event);
};
