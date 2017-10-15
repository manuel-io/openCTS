#include "../include/map.hpp"
#include "../include/form.hpp"
#include "../include/menu.hpp"

namespace Menu
{
  Start::Start()
  {
    Game::map = new Map();
    background = TextureManager::loadTexture("assets/menu/transit.png");
    buttons[0] = new NewGame(410, 5, 380, 120);
    buttons[1] = new LoadGame(410, 125, 380, 120);
    buttons[2] = new NewMap(410, 245, 380, 120);
    buttons[3] = new LoadMap(410, 365, 380, 120);
    buttons[4] = new Settings(410, 485, 380, 120);
    buttons[5] = new Credits(410, 605, 380, 120);
  }

  Start::~Start()
  {
    SDL_DestroyTexture(background);
    for (int i = 0; i < 6; i++) {
      delete buttons[i];
    }
  }

  void Start::handle(SDL_Event event)
  {
    switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:

        if (selected) {
          selected->handle(event);
        }
        else
        {
          for (int i = 0; i < 6; i++) {
            if (buttons[i]->selected(event.button.x, event.button.y, 50)) {
              selected = buttons[i];
            } 
          }
        }
        break;
    }
  }

  void
  Start::render()
  { 
    if (selected) {

      selected->render();
    
    } else {

      SDL_RenderClear(Game::renderer);
      SDL_Rect dest = { .x = 0, .y = 0, .w = 800, .h = 700 };
      TextureManager::draw(background, dest);
    
      for (int i = 0; i < 6; i++) {
        buttons[i]->icon();
      }
    }

    SDL_RenderPresent(Game::renderer);
  }

  void
  Start::update()
  {
    if (selected) {
      selected->update();
    }
  }
};
