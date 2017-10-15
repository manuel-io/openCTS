#ifndef STATE_H
#define STATE_H

#include "game.hpp"
#include "form.hpp"

class Submenu;

class State {
public:
  State();
  virtual ~State();
  virtual void handle(SDL_Event);
  virtual void render();
  virtual void update();
};

#endif /* STATE_H */

#ifndef INTRO_H
#define INTRO_H

namespace Intro {
  class Start : public State {
  public:
    Start() { };
    void render() { Game::changeState(MENU); };
  };
};

#endif /* INTRO_H*/

#ifndef STATEMENU_H
#define STATEMENU_H

namespace Menu {
  class Start : public State {
  public:
    Start();
    ~Start();
    void handle(SDL_Event);
    void render();
    void update();
  private:
    SDL_Rect src;
    SDL_Texture *background;
    Form::Button *buttons[6] = { 0, 0, 0, 0, 0, 0 };
    Form::Button *selected = nullptr;
  };
};

#endif /* STATEMENU_H */

#ifndef PLAY_H
#define PLAY_H

namespace Play {

  class Menu {
  public:
    Menu();
    ~Menu();
  
    void update();
    void render();
    void handle(SDL_Event);

  private:
    SDL_Rect rect = { .x = 0, .y = 570, .w = 800, .h = 150 };
    Form::Button *buttons[6] = { 0, 0, 0, 0, 0, 0 };
    Form::Button *selected = nullptr;
  };

  class Start : public State {
  public:

    Start();
    ~Start();

    Menu *menu;

    void handle(SDL_Event);
    void render();
    void update();
  };
};

#endif /* PLAY_H */

#ifndef EDITOR_H
#define EDITOR_H

namespace Editor {

  class Menu {
  public:
    Menu();
    ~Menu();
  
    void update();
    void render();
    void handle(SDL_Event);

  private:
    SDL_Rect rect = { .x = 0, .y = 570, .w = 800, .h = 150 };
    Form::Button *buttons[6] = { 0, 0, 0, 0, 0, 0 };
    Form::Button *selected = nullptr;
  };

  class Start : public State {
  public:

    Start();
    ~Start();

    Menu *menu;

    void handle(SDL_Event);
    void render();
    void update();
  };
};

#endif /* EDITOR_H */

#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings {
  class Start : public State {
  public:
    Start() { };
    void render() { Game::changeState(INTRO); };
  };
};

#endif /* SETTINGS_H*/
