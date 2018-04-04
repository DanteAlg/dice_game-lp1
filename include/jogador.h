#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>

class Jogador {
  private:
    std::string nome;

  public:
    Jogador(std::string nome_);
    ~Jogador();

    std::string getName();
};
#endif
