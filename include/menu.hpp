#ifndef MENU_H
#define MENU_H

namespace Menu {
  class NewGame : public Form::Button {
  public:
    NewGame(int x, int y, int w, int h) : Form::Button("New Game", "assets/menu/newgame.png", x, y, w, h) {}; 
    void update() { Game::changeState(PLAY); }
  };

  class LoadGame : public Form::Button {
  public:
    LoadGame(int x, int y, int w, int h) : Form::Button("Load Game", "assets/menu/loadgame.png", x, y, w, h) {};
  };

  class NewMap : public Form::Button {
  public:
    NewMap(int x, int y, int w, int h) : Form::Button("New Map", "assets/menu/newmap.png", x, y, w, h) {};
    void update() { Game::changeState(EDITOR); }
  };

  class LoadMap : public Form::Button {
  public:
    LoadMap(int x, int y, int w, int h) : Form::Button("Load Map", "assets/menu/loadmap.png", x, y, w, h) {};
  };

  class Settings : public Form::Button {
  public:
    Settings(int x, int y, int w, int h) : Form::Button("Settings", "assets/menu/settings.png", x, y, w, h) {};
  };

  class Credits : public Form::Button {
  public:
    Credits(int, int, int, int);
    ~Credits();

    void handle(SDL_Event);
    void render();
    void update();
  private:
    Form::Button *exit;
    SDL_Texture *texture, *credits;
    SDL_Color color = { 255, 255, 255 };
  };

  class ExitMode : public Form::Button {
  public:
    ExitMode(int x, int y, int w, int h) : Form::Button("Exit", "assets/menu/settings.png", x, y, w, h) {};
  };
};

#endif /* MENU_H */
