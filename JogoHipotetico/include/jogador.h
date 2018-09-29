//Criação da classe jogador
#ifndef JOGADOR_H
#define JOGADOR_H


#include <iostream>
#include <string>
#include "dado.h"
using namespace std;

class Jogador {
private:
  char m_decisao;
  string  m_nome;
  int m_pontos;
  bool m_ativo;

public:
  static int valor_maximo;
  Jogador (const string nome_);
  ~Jogador ();
  int getPontos();
  bool isAtivo();
  string getNome();
  void jogar(Dado &d1, Dado &d2);
  void desativar();
  void alterar_decisao(const char decisao_);
  char getDecisao();
  friend std::ostream& operator<< (std::ostream &o, Jogador * j);
  bool operator== (Jogador * player);
};


#endif
