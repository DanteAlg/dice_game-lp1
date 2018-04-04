#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "player.h"

class Game {
  private:
    int topValue;
    int round;
    int winner;
    std::vector <Player> players;

    int playerRound(Player &p);
    int diceRoll();
    bool playRound(Player &p);
    void printWinner(int plays);
    void verifyWinner();


  public:
    Game(int topValue_);
    ~Game();

    void addPlayer(Player *p);
    void start();

    friend std::ostream& operator<<(std::ostream &o, Player const player);
};
#endif
