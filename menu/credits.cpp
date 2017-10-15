#include "../include/texture.hpp"
#include "../include/form.hpp"
#include "../include/menu.hpp"

namespace Menu
{
  Credits::Credits(int x, int y, int w, int h) : Form::Button("Credits", "assets/menu/credits.png", x, y, w, h)
  {
    exit = new ExitMode(400, 50, 374, 70);
    texture = TextureManager::loadTexture("assets/menu/transit.png");

    /* SDL_RWops *io = SDL_RWFromFile("CREDITS", "rb");
     * if (io != NULL) {
     *   char text[20];
     *   if (SDL_RWread(io, text, sizeof(text), 1) == 0) {
     *     credits = TextureManager::loadFont(text, color);
     *   }
     *
     *   SDL_RWclose(io);
     * }
     */
  }

  Credits::~Credits()
  {
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(credits);
  }

  void
  Credits::handle(SDL_Event event)
  {
    switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:
        if (exit->selected(event.button.x, event.button.y, 0)) {
          Game::changeState(MENU);
        }
        break;
    }
  }
 
  void
  Credits::render()
  {
    SDL_RenderClear(Game::renderer);
    SDL_Rect dest = { .x = 0, .y = 0, .w = 800, .h = 700 };
    TextureManager::draw(texture, dest);
   /* 
    SDL_QueryTexture(credits, NULL, NULL, &dest.w, &dest.h);
    dest.x = 200;
    TextureManager::draw(credits, dest);
    */
    exit->icon();
  }

  void
  Credits::update()
  {
  }
};
