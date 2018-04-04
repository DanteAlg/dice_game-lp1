#ifndef JOGO_H
#define JOGO_H

#include <iostream>

#include "jogador.h"

#define MAX_JOGADORES 5

class Jogo {
  private:
    int valorMax;
    Jogador *jogadores[MAX_JOGADORES];

  public:
    Jogo(int valorMax_);
    ~Jogo();

    void Jogo::addJogador(Jogador *j);
};
#endif
