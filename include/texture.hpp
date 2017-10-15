#ifndef TEXTURE_H
#define TEXTURE_H

#include "game.hpp"

class TextureManager {

public:
  static SDL_Texture *loadTexture(const char *);
  static SDL_Texture *loadFont(const char *, SDL_Color);
  static void draw(SDL_Texture *, SDL_Rect);
  static void draw(SDL_Texture *, SDL_Rect, SDL_Rect);

private:

};

#endif /* TEXTURE_H */
