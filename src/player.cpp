#include "player.h"

Player::Player(std::string name_) : status(ON_GAME), accumulated_value(0) {
  name = name_;
}

Player::~Player() {}

std::string Player::getName() { return name; }

int Player::getValue() { return accumulated_value; }

int Player::getStatus() { return status; }

void Player::setStatus(int status_) {
  status = status_;
}

void Player::accumulate(int value) {
  accumulated_value += value;
}

std::ostream& operator<<(std::ostream &o, Player const player) {
  o << player.name;

  return o;
}
