#include "game.h"

#define DICE_SIZE 6

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

  std::cout << "Iniciando o jogo..." << std::endl;

  while(on_game) {
    round++;

    for(int i = 0; i < players.size(); i++) {
      if (winner < 0 && players[i].getStatus() != LOSE)
        plays += playerRound(i);

      if (players[i].getStatus() == WINNER)
        winner = i;
    }

    if (plays == 0 || winner >= 0)
      on_game = false;

    plays = 0;
    printRound(round);
  }

  verifyWinner();
  printWinner(plays);
}

// Private methods

void Game::printRound(int round) {
  std::cout << "ROUND: " << round << " <------------------------->" << std::endl;

  for(int i = 0; i < players.size(); i++) {
    std::cout << "Player " << players[i] << " -> " << players[i].getValue() << std::endl;
  }

  std::cout << std::endl << std::endl;
}

int Game::playerRound(int id) {
  int value;

  if (playRound(id)) {
    value = diceRoll() + diceRoll();
    players[id].accumulate(value);
  }
  else
    return 0;

  if (players[id].getValue() > topValue)
    players[id].setStatus(LOSE);
  else if (players[id].getValue() == topValue)
    players[id].setStatus(WINNER);

  return 1;
}

// Use radom generator of C++ and pass this to dice class
int Game::diceRoll() {
  return dice1.roll() + dice2.roll();
}

bool Game::playRound(int id) {
  int player_value = players[id].getValue();

  if (player_value < topValue - DICE_SIZE*2) return true;
  else
    for(int i = 0; i < players.size(); i++)
      if (id != i && players[i].getValue() < topValue && players[i].getValue() >= player_value)
        return true;

  return false;
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
