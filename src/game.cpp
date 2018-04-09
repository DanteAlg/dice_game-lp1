#include "game.h"

#define DICE_SIZE 6

Game::Game(int topValue_) : round(0), winner(-1) {
  topValue = topValue_;
}

Game::~Game() {}

// This method add a new user object on players vector
void Game::addPlayer(Player *p) {
  players.push_back(*p);
  std::cout << "-> Adicionado jogador " << *p << std::endl;
}

// This method start the game
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

// Print users informations in current round
void Game::printRound(int round) {
  std::cout << "ROUND: " << round << " <------------------------->" << std::endl;

  for(int i = 0; i < players.size(); i++) {
    std::cout << "Player " << players[i] << " -> " << players[i].getValue() << std::endl;
  }

  std::cout << std::endl << std::endl;
}

// Execute user round
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

// Roll two dices
int Game::diceRoll() {
  return dice1.roll() + dice2.roll();
}

// Verify if user will play round.
// If user sum is smaller than sum of two dices so he plays
// Else verify if any user have a cumulative value bigger
bool Game::playRound(int id) {
  int player_value = players[id].getValue();

  if (player_value < topValue - DICE_SIZE*2) return true;
  else
    for(int i = 0; i < players.size(); i++)
      if (id != i && players[i].getValue() < topValue && players[i].getValue() >= player_value)
        return true;

  return false;
}

// Print informations of winner
void Game::printWinner(int plays) {
  if (plays == 0 && winner < 0) {
    std::cout << "Empate, todos passaram do valor máximo :(" << std::endl;
  }
  else {
    std::cout << "Ganhador: " << players[winner] << std::endl;
  }
}

// This method verify if any user have a 'win' status
// If all users have a 'LOSE' status so game is drawn
// Else verify which user have a cumulative value more closest of top game value
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
