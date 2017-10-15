#ifndef BUTTON_H
#define BUTTON_H

#include "game.hpp"

namespace Form {

  class Button {
  public:
    Button(const char *, const char *, int, int, int, int);
    virtual ~Button();

    bool selected (int x, int y, int yoff)
    {
      if (x > dest.x && x < dest.x + dest.w) {
        if (y > dest.y && y < dest.y + dest.h - yoff) {
          return true;
        }
      }
      return false;
    }

    void icon();
    virtual void handle(SDL_Event);
    virtual void render();
    virtual void update();

  private:
    const char *title;
    SDL_Rect dest;
    SDL_Texture *tex;
  };
};

#endif /* BUTTON_H */

