#include <iostream>

#include "player.h"
#include "game.h"

int main() {
  Game game(50);
  game.addPlayer(new Player("Player 42"));
  game.addPlayer(new Player("Fus ro dah"));
  game.addPlayer(new Player("Player Eleven"));
  game.start();

  return 0;
}
