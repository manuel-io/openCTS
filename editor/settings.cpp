#include "../include/obj.hpp"
#include "../include/texture.hpp"
#include "../include/form.hpp"
#include "../include/map.hpp"
#include "../include/editor.hpp"

namespace Editor {

  Settings::Settings(const char *a, const char *b, int spos, int epos, int x, int y, int w, int h) : Form::Button(a, b, x, y, w, h)
  {
    startpos = spos;
    endpos = epos;
    scroll = 0;
  }

  Settings::~Settings()
  {

  }

  void
  Settings::handle(SDL_Event event)
  {
    switch(event.type) {

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_UP: scroll -= 20; break;
          case SDLK_DOWN: scroll += 20; break;
        }
        break;

      case SDL_MOUSEBUTTONDOWN:
        int y = event.button.y - 570 + scroll;
        y = y / 20 + startpos;
        if (Map::objs[y]) {
          Map::selected = Map::objs[y];
        }
        break;
    }
  }

  void
  Settings::render()
  {
    SDL_Texture *tex = nullptr;
    SDL_Rect dest;

    for (int i = startpos; i < endpos; i++) {
      if (i % 2 == 0) {
        SDL_SetRenderDrawColor(Game::renderer, 217, 217, 217, 255);
        color = { 71, 71, 71 };
      }
      else  {
        SDL_SetRenderDrawColor(Game::renderer, 71, 71, 71, 255);
        color = { 217, 217, 217 };
      }

      tex = TextureManager::loadFont(Map::objs[i]->getTitle(), color);    
      SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
      dest.x = 200;
      dest.y = 570 + (i - startpos) * 20 - scroll;

      if (dest.y >= 570) {
        rect.y = 570 + (i - startpos) * 20 - scroll;
        rect.h = 20;
        SDL_RenderFillRect(Game::renderer, &rect);
        TextureManager::draw(tex, dest);
      }
      SDL_DestroyTexture(tex);
    }
    
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
  }
};
