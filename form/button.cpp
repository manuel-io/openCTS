#include "../include/texture.hpp"
#include "../include/form.hpp"

namespace Form {

  Button::Button(const char *t, const char *a, int x, int y, int w, int h)
  {
    title = t;
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
    tex = TextureManager::loadTexture(a);
  }

  Button::~Button()
  {
    SDL_DestroyTexture(tex);
  }

  void
  Button::handle(SDL_Event event)
  {
  }

  void
  Button::icon()
  {
    TextureManager::draw(tex, dest);
  }

  void
  Button::render()
  {
    std::cout << "Override me" << std::endl;
  }

  void
  Button::update()
  {
  
  }

};
