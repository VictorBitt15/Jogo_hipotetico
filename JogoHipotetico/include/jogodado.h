//Criação da classe Jogodado
#ifndef JOGODADO_H
#define JOGODADO_H

#include <string>
#include <iostream>
#include "jogador.h"
#include "dado.h"
using namespace std;

#define MAX_JOGADORES 10

class Jogodado {
private:
  char m_jogador_decisao;
  Jogador * m_jogadores[MAX_JOGADORES];
  int m_total_jogadores;
  Dado * m_dados[2];
  int m_rodada;
  int m_ativos;
  Jogador * m_vencedor;

public:
  Jogodado();
  ~Jogodado ();
  void addJogador(Jogador * Player);
  int getTotalJogadores();
  int getRodada();
  int getAtivos();
  Jogador * getVencedor();
  void start();
  bool decisaoJogar(Jogador * jogador_);
  bool desativaPlayer();
  void imprime_dados_rodada();
  bool decide_Vencedor();
  void imprimeVencedor();
  bool verifica_fim();
  void imprimeVencedor_fim();
};

#endif
