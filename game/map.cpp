#include "../include/map.hpp"
#include "../include/texture.hpp"

  unsigned char lvl1[30][30] = {
    {12,12,12,12,20,20,12,12,25,25,12,12,11,12,12,12,84,88,81,81,81,81,81,81,81,81,88,81,86,12},
    {12,12,12,84,81,81,81,88,81,81,81,81,91,81,81,81,87,90,12,12,12,12,12,12,26,12,82,12,12,12},
    {12,12,22,82,12,12,20,82,12,12,12,12,11,84,81,81,81,80,81,81,81,81,81,81,81,81,80,81,81,81},
    {12,12,23,82,12,12,12,83,81,81,85,12,11,82,84,81,81,80,81,81,81,81,81,81,81,81,80,81,81,81},
    {81,81,81,90,12,12,12,12,12,12,82,12,11,82,82,12,12,82,12,12,12,12,12,12,12,12,82,12,12,12},
    {12,12,12,82,12,12,12,12,12,12,82,12,11,82,82,12,12,82,12,12,12,12,12,12,12,12,82,12,12,12},
    {12,12,12,82,21,12,12,12,27,24,82,12,11,82,82,12,12,83,81,81,85,12,12,84,81,81,90,12,12,12},
    {12,12,12,89,81,81,81,81,81,81,80,85,11,82,82,12,12,12,12,12,82,12,12,82,12,12,82,12,12,12},
    {12,12,12,82,12,21,12,12,12,12,83,90,11,82,82,12,12,12,12,12,82,12,12,82,12,12,82,12,12,12},
    {12,12,12,82,12,12,12,12,12,12,12,82,11,82,82,12,12,84,81,81,80,81,81,90,12,12,82,12,12,12},
    {12,12,12,82,12,12,12,84,85,12,12,82,11,82,82,12,12,82,12,12,82,12,12,82,12,12,82,12,12,12},
    {84,81,81,90,12,12,12,89,86,12,12,82,11,82,82,12,12,82,12,12,82,12,12,82,12,12,82,12,12,12},
    {82,12,12,82,12,12,12,82,12,12,12,82,11,82,82,12,12,82,12,12,82,12,12,82,12,12,82,12,12,12},
    {82,12,12,82,12,12,12,82,12,12,12,82,11,82,82,12,12,82,12,12,82,12,12,82,12,12,82,12,12,12},
    {82,12,12,83,88,81,81,87,81,81,81,90,11,89,80,81,81,87,81,81,87,81,81,80,81,81,87,81,81,88},
    {82,12,12,12,82,12,12,12,12,12,12,82,11,82,82,12,12,12,12,12,12,12,12,82,12,12,12,12,12,82},
    {82,12,12,12,82,12,12,12,12,12,12,82,11,82,82,12,12,12,12,12,12,12,12,82,12,12,12,12,12,82},
    {82,12,12,12,82,12,12,12,12,12,12,82,11,82,82,12,12,84,81,88,81,81,81,86,12,12,84,81,81,90},
    {83,81,81,81,87,81,81,81,88,81,81,90,11,82,82,12,12,82,12,82,12,12,12,12,12,12,82,12,12,82},
    {12,12,12,12,12,12,12,12,82,12,12,82,11,82,82,12,12,82,12,89,85,12,12,12,12,12,82,12,12,82},
    {12,12,12,12,12,12,12,12,82,12,12,82,11,82,82,12,12,82,12,83,87,81,81,88,81,81,86,12,12,82},
    {12,12,12,12,12,12,12,12,82,12,12,82,11,82,82,12,12,82,12,12,12,12,12,82,12,12,12,12,12,82},
    {84,85,12,12,12,12,12,12,82,12,12,82,11,82,82,12,12,82,12,12,12,12,12,82,12,12,12,12,12,82},
    {89,87,81,81,81,81,81,81,90,12,12,82,11,82,82,12,12,83,81,81,85,12,12,89,81,81,81,81,81,90},
    {82,12,12,12,12,12,12,12,82,12,12,82,11,92,92,11,11,11,11,11,92,11,11,92,11,11,11,11,11,92},
    {82,12,12,12,12,12,12,12,83,81,81,86,12,82,82,12,12,12,12,12,82,12,12,82,12,12,12,12,12,82},
    {82,12,12,12,12,12,12,12,12,12,12,12,12,89,80,81,81,88,81,81,87,81,81,86,12,12,12,12,12,82},
    {82,12,12,12,12,12,12,12,12,12,12,12,12,82,82,12,12,82,12,12,12,12,12,12,12,12,12,12,12,82},
    {89,81,81,81,81,81,81,81,81,81,81,81,81,86,82,12,84,90,12,12,12,12,12,12,12,12,12,12,12,82},
    {83,81,81,81,81,81,81,81,81,81,81,81,81,81,86,12,83,87,81,81,81,81,81,81,81,81,81,81,81,90}
  };

  SDL_Rect Map::camera = { .x = 400, .y = 0, .w = 800, .h = 640 };
  struct Point <int> Map::motion =  { .x = 0, .y = 0 };
  GameObject *Map::selected = nullptr;
  struct GameObject **Map::objs;

  Map::Map()
  {
    Map::objs = new GameObject *[OBJS];
    for (unsigned int i = 0; i < OBJS; i++) {
      Map::objs[i] = new GameObject(Game::objs[i].id, Game::objs[i].title, Game::objs[i].asset, Game::objs[i].width, Game::objs[i].height);
    }
    loadMap(lvl1);

    src.x = src.y = 0;
    dest.x = dest.y = 0;
    src.w = dest.w = 198;
    src.h = dest.h = 126;
  }

  Map::~Map()
  {
    //SDL_DestroyTexture(select);
    //SDL_DestroyTexture(grass);
  }

  Map::Map(int r, int c)
  {
    rows = r;
    columns = c;
    Map::objs = new GameObject *[OBJS];
    for (unsigned int i = 0; i < OBJS; i++) {
      Map::objs[i] = new GameObject(Game::objs[i].id, Game::objs[i].title, Game::objs[i].asset, Game::objs[i].width, Game::objs[i].height);
    }

    loadEmpty();

    src.x = src.y = 0;
    dest.x = dest.y = 0;
    src.w = dest.w = 198;
    src.h = dest.h = 126;
  }

  void
  Map::loadEmpty()
  {
    map = new unsigned char[rows * columns];

    for (int row = 0; row < rows; row++)
      for (int column = 0; column < columns; column++)
        map[row * rows + column] = 10;
  }

  void
  Map::loadMap(unsigned char arr[30][30])
  {
    rows = 30;
    columns = 30;
    map = new unsigned char[rows * columns];

    for (int row = 0; row < 30; row++)
      for (int column = 0; column < 30; column++) {
        map[row * rows + column] = arr[row][column];
      }
  }

  void
  Map::drawMap()
  {
    int type = 0;

    for (int row = 0; row < rows; row++) {
      for (int column = 0; column < columns; column++) {
        type = map[row * rows + column];
        
        dest.x = Map::camera.x + (column - row) * 99 - 99;
        dest.y = Map::camera.y + (column + row) * 63;

        Map::objs[type]->render(dest.x, dest.y);
      }
    }
  }

  void
  Map::drawEvent()
  {
    struct Point <double> iso;
    int column, row;
    
    iso.x = (screen.y + screen.x/1.5714) / 126;
    iso.y = (screen.y - screen.x/1.5714) / 126;

    column = std::floor(iso.x);
    row = std::floor(iso.y);

    dest.x = Map::camera.x + (column - row) * 99 - 99;
    dest.y = Map::camera.y + (column + row) * 63;

    if (Map::selected) {
      Map::selected->render(dest.x, dest.y);
    }
  }

  void
  Map::handle(SDL_Event event)
  {
    if (SDL_GetRelativeMouseMode()) {
      Map::motion.x = 0;
      Map::motion.y = 0;
    }

    switch (event.type) {

      case SDL_KEYDOWN:
        if (!SDL_GetRelativeMouseMode())
          switch (event.key.keysym.sym) {
            case SDLK_UP: Map::motion.y = +10; break;
            case SDLK_DOWN: Map::motion.y = -10; break;
            case SDLK_LEFT: Map::motion.x = +10; break;
            case SDLK_RIGHT: Map::motion.x = -10; break;
          }
        break;

      case SDL_KEYUP:
        switch (event.key.keysym.sym) {
          case SDLK_UP: Map::motion.y = 0; break;
          case SDLK_DOWN: Map::motion.y = 0; break;
          case SDLK_LEFT: Map::motion.x = 0; break;
          case SDLK_RIGHT: Map::motion.x = 0; break;
        }
        break;

      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (Map::selected) {

              struct Point <double> iso;
              int column, row;
              iso.x = (screen.y + screen.x/1.5714) / 126;
              iso.y = (screen.y - screen.x/1.5714) / 126;
              column = std::floor(iso.x);
              row = std::floor(iso.y);
              map[row * rows + column] = Map::selected->getId();
            }
        }
        if (event.button.button == SDL_BUTTON_RIGHT) {
          SDL_ShowCursor(SDL_DISABLE);
          SDL_SetRelativeMouseMode(SDL_TRUE);
        }
        break;

      case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_RIGHT) {
          SDL_SetRelativeMouseMode(SDL_FALSE);
          SDL_ShowCursor(SDL_ENABLE);
        }
        break;

      case SDL_MOUSEMOTION:
        screen.x = event.button.x - Map::camera.x;
        screen.y = event.button.y - Map::camera.y;
        if (event.motion.state & SDL_BUTTON_RMASK) {
          Map::motion.x = -2 * event.motion.xrel;
          Map::motion.y = -2 * event.motion.yrel;
        }
        break;
    }
  }

void
Map::update()
{
  Map::camera.x += Map::motion.x;
  Map::camera.y += Map::motion.y;
}
