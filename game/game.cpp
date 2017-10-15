#include "../include/state.hpp"
#include "../include/game.hpp"
#include "../include/objs.hpp"

Map *Game::map = nullptr;
State *Game::state = nullptr;
State *Game::oldstate = nullptr;
SDL_Renderer *Game::renderer = nullptr;
TTF_Font *Game::font = nullptr;

void
Game::changeState(States mode)
{
  delete Game::oldstate;
  Game::oldstate = Game::state;

  switch(mode) {
    case INTRO:
      state = new Intro::Start();
      break;
    case MENU:
      state = new Menu::Start();
      break;
    case PLAY:
      state = new Play::Start();
      break;
    case EDITOR:
      state = new Editor::Start();
      break;
    case SETTINGS:
      state = new Settings::Start();
      break;
  }
}

Game::Game(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  int flags = 0;
  if (fullscreen) {
      flags |= SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
      std::cout << "Subsystems ready" << std::endl;
      window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

      if (window) {
          std::cout << "Window created!" << std::endl;
      }

      Game::renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

      if (Game::renderer) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        std::cout << "Renderer created!" << std::endl;
      }

      isRunning = true;
  }
  else
  {
    isRunning = false;
  }
}

Game::~Game() {
  if (Game::state) {
    delete Game::state;
  }
}


void
Game::init()
{
  TTF_Init();
  Game::font = TTF_OpenFont("assets/fonts/hermit.ttf", 14);
  Game::state = new Intro::Start();
}

void
Game::handle()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  
  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
    break;

    default:
      Game::state->handle(event);
  }
}

void
Game::render()
{
  Game::state->render();
}

void
Game::update()
{
  Game::state->update();
}

void
Game::clean()
{
  SDL_DestroyRenderer(Game::renderer);
  SDL_DestroyWindow(window);

  TTF_CloseFont(Game::font);
  TTF_Quit();
  SDL_Quit();

  std::cout << "Game cleaned" << std::endl;
}
