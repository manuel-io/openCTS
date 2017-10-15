#include "../include/obj.hpp"
#include "../include/map.hpp"
#include "../include/state.hpp"

namespace Play {

  Start::Start()
  {
    Game::map = new Map();
    menu = new Menu();
  }

  Start::~Start()
  {
    delete Game::map;
    delete menu;
  }

  void
  Start::handle(SDL_Event event)
  {
    switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:

        if (event.button.y < 570) {
          Game::map->handle(event);
        }

        if (event.button.y >= 570) {
          menu->handle(event);
        }
        break;
    
      default:
        Game::map->handle(event);
    }
  }

  void
  Start::render()
  {
    SDL_RenderClear(Game::renderer);
  
    Game::map->drawMap();
    Game::map->drawEvent();
    menu->render();
  
    SDL_RenderPresent(Game::renderer);
  }

  void
  Start::update()
  {
    Game::map->update();
    menu->update();
  }
};
