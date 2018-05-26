#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cmath>

#define OBJS 100

template <typename T>
struct Point {
  T x;
  T y;
};

struct Objs {
  unsigned char id;
  const char *title;
  const char *asset;
  int width;
  int height;
  unsigned int people;
  unsigned int pupil;
};

class Map;
class State;
enum States { INTRO, MENU, PLAY, EDITOR, SETTINGS };

class Game {

public:
  Game(const char *, int, int, int, int, bool);
  ~Game();

  void clean();
  void init();
  void handle();
  void render();
  void update();

  bool running() { return isRunning; }

  static TTF_Font *font;
  static SDL_Renderer *renderer;
  static struct Objs objs[OBJS];

  static Map *map;
  static State *state;
  static State *oldstate;
  static void changeState(States);

private:
    bool isRunning;
    SDL_Window *window;
};

#endif /* GAME_H */
