#include "../include/map.hpp"
#include "../include/texture.hpp"
#include "../include/state.hpp"
#include "../include/form.hpp"
#include "../include/editor.hpp"

namespace Editor {

  Menu::Menu()
  {
    buttons[0] = new Items("Botany", "assets/menu/botany.png", 10, 20,  10 + 50 + 10 + 50 + 10, 570 + 1 * 10, 50, 50);
    buttons[1] = new Items("Streets", "assets/menu/streets.png", 80, 100, 10, 570 + 10, 50, 50);  
    buttons[2] = new Items("Residentials", "assets/menu/residentials.png", 20, 40, 10, 570 + 50 + 2 * 10, 50, 50);
    buttons[3] = new Items("Work", "assets/menu/work.png", 40, 60, 10 + 50 + 10, 570 + 50 + 2 * 10, 50, 50);
    buttons[4] = new Items("Infrastructure", "assets/menu/infrastructure.png", 60, 80, 10 + 50 + 10, 570 + 10, 50, 50);
    buttons[5] = new Settings("Settings", "assets/menu/man.png", 0, 0, 10 + 50 + 10 + 50 + 10, 570 + 50 + 2 * 10, 50, 50);

    selected = buttons[0];
  }

  Menu::~Menu()
  {

  }

  void
  Menu::handle(SDL_Event event)
  {
    switch(event.type) {
      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
          for (int i = 0; i < 6; i++) {
            if (buttons[i]->selected(event.button.x, event.button.y, 0)) {
              selected = buttons[i];
              break;
            }
          }
        }
        break;
    }

    if (selected) {
      selected->handle(event);
    }
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
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    for (int i = 0; i < 6; i++) {
      buttons[i]->icon();
    }

    if (selected) {
      selected->render();
    }
  }
};
