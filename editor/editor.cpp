#include "../include/map.hpp"
#include "../include/state.hpp"

namespace Editor
{
  Start::Start()
  {
    Game::map = new Map(30, 30);
    menu = new Menu();
  }

  Start::~Start()
  { 
    delete Game::map;
  }

  void Start::handle(SDL_Event event)
  {
    int x, y;
    SDL_GetMouseState(&x, &y);

    if (y < 570) {
      Game::map->handle(event);
    }
    
    if (y >= 570) {
      menu->handle(event);
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
    menu->render();
  }
};
