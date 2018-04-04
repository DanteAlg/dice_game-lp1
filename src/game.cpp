#include "game.h"

Game::Game(int topValue_) : round(0), winner(-1) {
  topValue = topValue_;
}

Game::~Game() {}

void Game::addPlayer(Player *p) {
  players.push_back(*p);
  std::cout << "-> Adicionado jogador " << *p << std::endl;
}

void Game::start() {
  if (players.size() == 0) {
    std::cout << "Precisamos de ao menos um jogador para iniciar..." << std::endl;
    return;
  }

  int plays = 0;
  bool on_game = true;

  while(on_game) {
    round++;

    for(int i = 0; i < players.size(); i++) {
      if (winner < 0 && players[i].getStatus() != LOSE)
        plays += playerRound(players[i]);

      if (players[i].getStatus() == WINNER)
        winner = i;
    }

    if (plays == 0)
      on_game = false;

    plays = 0;
  }

  verifyWinner();
  printWinner(plays);
}

// Private methods

int Game::playerRound(Player &p) {
  int value;

  if (playRound(p)) {
    value = diceRoll() + diceRoll();
    p.accumulate(value);
  }
  else
    return 0;

  if (p.getValue() > topValue)
    p.setStatus(LOSE);
  else if (p.getValue() == topValue)
    p.setStatus(WINNER);

  return 1;
}

int Game::diceRoll() {
  std::srand(time(NULL));
  return (std::rand()%6+1);
}

// TODO: Implement rule to play round
bool Game::playRound(Player &p) {
  return true;
}

void Game::printWinner(int plays) {
  if (plays == 0 && winner < 0) {
    std::cout << "Empate, todos passaram do valor máximo :(" << std::endl;
  }
  else {
    std::cout << "Ganhador: " << players[winner] << std::endl;
  }
}

void Game::verifyWinner() {
  int win_cumulative = 0;

  if (winner < 0) {
    for(int i = 0; i < players.size(); i++) {
      if (players[i].getStatus() != LOSE && players[i].getValue() > win_cumulative) {
        win_cumulative = players[i].getValue();
        winner = i;
      }
    }
  }
}
