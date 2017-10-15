#ifndef MAP_H
#define MAP_H

#include "state.hpp"
#include "texture.hpp"
#include "obj.hpp"

class Map {
public:
  Map();
  Map(int, int);
  ~Map();

  static SDL_Rect camera;
  static struct Point <int> motion;
  static GameObject *selected;
  static struct GameObject **objs;

  void handle(SDL_Event);
  void update();
  void loadMap(unsigned char arr[30][30]);
  void drawMap();
  void drawEvent();

private:
  void loadEmpty();

  struct Point <int> screen;

  SDL_Rect src, dest;

  unsigned char *map;

  int xoffset = 0;
  int yoffset = 0;
  int columns;
  int rows;
};

#endif /* MAP_H */
