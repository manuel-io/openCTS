#ifndef SUBMENU_H
#define SUBMENU_H

#include "game.hpp"

class GameObject;
class Tabmenu;

class Submenu {
public:
  Submenu(const char *, const char *, int, int, int, int);
  ~Submenu();

  bool selected (int x, int y) {
    if (x > xpos && x < xpos + width) {
      if (y > ypos && y < ypos + height) {
        return true;
      }
    }
    return false;
  }

  virtual void handle(SDL_Event);
  void update();
  void render();

  static Tabmenu *tabmenus[4];
  static Tabmenu *oldmenus[4];
  static Tabmenu *tabselect;

private:
  int xpos = 0;
  int ypos = 0;
  int width = 50;
  int height = 50;
  const char *title;

  GameObject *obj;

  void clear();
};

#endif /* SUMENU_H */

#ifndef STATS_H
#define STATS_H

class Stats : public Submenu {
public:
  Stats(int x, int y, int w, int h) : Submenu("Statistics", "assets/menu/stats.png", x, y, w, h) {};
  ~Stats() {};
  void handle(SDL_Event);
};

#endif /* STATS_H */

#ifndef MARKET_H
#define MARKET_H

class Market : public Submenu {
public:
  Market(int x, int y, int w, int h) : Submenu("Market", "assets/menu/market.png", x, y, w, h) {};
  ~Market() {};
  void handle(SDL_Event);
};

#endif /* MARKET_H */

#ifndef PLANER_H
#define PLANER_H

class Planer : public Submenu {
public:
  Planer(int x, int y, int w, int h) : Submenu("Planer", "assets/menu/planer.png", x, y, w, h) {};
  ~Planer() {};
  void handle(SDL_Event);
};

#endif /* PLANER_H */

#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

class Construction : public Submenu {
public:
  Construction(int x, int y, int w, int h) : Submenu("Construction", "assets/menu/construction.png", x, y, w, h) {};
  ~Construction() {};
  void handle(SDL_Event);
};

#endif /* CONSTRUCTION_H */

#ifndef MAP_H
#define MAP_H

class Overview: public Submenu {
public:
  Overview(int x, int y, int w, int h) : Submenu("Map", "assets/menu/map.png", x, y, w, h) {};
  ~Overview() {};
  void handle(SDL_Event);
};

#endif /* MAP_H */

#ifndef MANAGEMENT_H
#define MANAGEMENT_H

class Management : public Submenu {
public:
  Management(int x, int y, int w, int h) : Submenu("Management", "assets/menu/management.png", x, y, w, h) {};
  ~Management() {};
  void handle(SDL_Event);
};

#endif /* MANAGEMENT_H */
