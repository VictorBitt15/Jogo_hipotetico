//Implementação do main.cpp
#include <iostream>
#include "jogodado.h"
#include "jogador.h"
int Jogador::valor_maximo=0;
using namespace std;
int main(int argc, char const *argv[]) {
  Jogodado game;

  game.addJogador(new Jogador("Jogador 1"));
  game.addJogador(new Jogador("Jogador 2"));
  game.addJogador(new Jogador("Jogador 3"));
  game.addJogador(new Jogador("Jogador 4"));
  cout << "Defina o máximo do jogo!" << endl;
  cin >> Jogador::valor_maximo;
  game.start();

  return 0;
}
