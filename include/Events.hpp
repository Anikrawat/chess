#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "Board.hpp"
#include <SDL2/SDL_events.h>
class Events {
public:
  int mouseX, mouseY;
  SDL_Event event;
  void allEvents(bool &, Board &);
};

#endif // !EVENTS_HPP
