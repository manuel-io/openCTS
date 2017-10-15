#include "../include/state.hpp"
#include "../include/form.hpp"
#include "../include/play.hpp"

namespace Play {

  Menu::Menu()
  {
    buttons[0] = new Stats(10, 570 + 10, 50, 50);  
    buttons[1] = new Planer(10, 570 + 50 + 2 * 10, 50, 50);
    buttons[2] = new Market(10 + 50 + 10, 570 + 10, 50, 50);
    buttons[3] = new Construction(10 + 50 + 10, 570 + 50 + 2 * 10, 50, 50);
    buttons[4] = new Overview(10 + 50 + 10 + 50 + 10, 570 + 1 * 10, 50, 50);
    buttons[5] = new Management(10 + 50 + 10 + 50 + 10, 570 + 50 + 2 * 10, 50, 50);
  }

  Menu::~Menu()
  {

  }

  void
  Menu::handle(SDL_Event event)
  {
  }

  void
  Menu::update()
  {
  }

  void
  Menu::render()
  {
    SDL_SetRenderDrawColor(Game::renderer, 55, 55, 55, 255);
    SDL_RenderFillRect(Game::renderer, &rect);
    for (int i = 0; i < 6; i++) {
      buttons[i]->icon();
    }
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
  }
};
