#ifndef GameObject_H
#define GameObject_H

#include "game.hpp"

class GameObject {
public:
  GameObject(unsigned char, const char *, const char *, int, int);
  ~GameObject();

  void handle(SDL_Event);
  unsigned char getId();
  const char *getTitle();
  void update();
  void render();
  void render(int, int);

private:
  const char *title;
  unsigned char id;
  SDL_Rect rect;
  SDL_Texture *tex;
};

#endif /* GameObject_H */
