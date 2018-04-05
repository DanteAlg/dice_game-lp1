#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "player.h"
#include "dice.h"

class Game {
  private:
    int topValue;
    int round;
    int winner;
    std::vector <Player> players;
    Dice dice1;
    Dice dice2;

    void printRound(int round);
    int playerRound(int id);
    int diceRoll();
    bool playRound(int id);
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
