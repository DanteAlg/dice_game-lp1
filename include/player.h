#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

enum Status {
  ON_GAME = 1,
  STOPPED = 2,
  LOSE = 3,
  WINNER = 4
};

class Player {
  private:
    std::string name;
    int status;
    int accumulated_value;

  public:
    Player(std::string name_);
    ~Player();

    std::string getName();
    int getValue();
    int getStatus();

    void setStatus(int state);
    void accumulate(int value);

    friend std::ostream& operator<<(std::ostream &o, Player const player);
};
#endif
