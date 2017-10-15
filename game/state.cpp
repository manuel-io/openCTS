#include "../include/state.hpp"

State::State()
{}

State::~State()
{}

void
State::handle(SDL_Event)
{
  std::cout << "State has no handle()" << std::endl;
}

void
State::render()
{}

void
State::update()
{}
