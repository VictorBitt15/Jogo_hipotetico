#include "jogodado.h"
#include "dado.h"
#include "jogador.h"
#include <iostream>
#include <string>
using namespace std;

//Construtor
Jogodado::Jogodado()
{
  m_jogador_decisao='U';
  m_total_jogadores=0;
  m_ativos=0;
  m_rodada=0;
  m_vencedor=nullptr;
  m_dados[0]= new Dado(6);
  m_dados[1]= new Dado(6);

}
//Destrutor
Jogodado::~Jogodado(){}

//Getters
int Jogodado::getTotalJogadores()
{
  return m_total_jogadores;
}
int Jogodado::getRodada()
{
  return m_rodada;
}
int Jogodado::getAtivos()
{
  return m_ativos;
}
Jogador * Jogodado::getVencedor()
{
  return m_vencedor;
}
//Fim dos Getters


//Método para adicionar Jogadores
void Jogodado::addJogador(Jogador * Player)
{
  if(m_total_jogadores<MAX_JOGADORES)
  {
    m_jogadores[m_total_jogadores++]=Player;
    m_ativos++;
  }
  else
  {
    cout << "O jogo já está completo!" << endl;
  }
}


//Iniciando jogo hipótetico
void Jogodado::start()
{
  while(m_ativos!=1)
  {
    cout << "------------- Rodada " << ++m_rodada  << " ----------------"<< endl;

    for(int i =0; i<getTotalJogadores(); i++)
    {
      if(m_rodada==1)
      {
        m_jogadores[i]->jogar(*m_dados[0], *m_dados[1]);
      }
      else
      {
        if(m_jogadores[i]->isAtivo())
        {
          if(decisaoJogar(m_jogadores[i]))
          {
            m_jogadores[i]->jogar(*m_dados[0],*m_dados[1]);
          }
        }
      }
    }
    imprime_dados_rodada();
    if(!desativaPlayer())
    {
        cout << "Ninguém teve pontos maiores que o informado!" << endl;

    }
    if(!decide_Vencedor())
    {
      cout << "Não houve vencedores nesta rodada!" << endl;
    }
    else
    {
      imprimeVencedor();
    }

    if(!verifica_fim())
    {
      cout << "Todos decidiram não jogar mais!" << endl;
      cout << endl;
      imprimeVencedor_fim();
      break;
    }
  }

}

//Método que decide se jogador está apto para jogar novamente
bool Jogodado::decisaoJogar(Jogador * jogador_)
{
  if(jogador_->getPontos() < Jogador::valor_maximo || jogador_->getPontos() == Jogador::valor_maximo){
    cout << jogador_->getNome() << " deseja jogar mais?\nN - Não\nS - Sim\n" << endl;
    cin >> m_jogador_decisao ;
    jogador_->alterar_decisao(m_jogador_decisao);
    return m_jogador_decisao == 'S';
  }
  jogador_->desativar();
  m_ativos--;
  return false;
}

//Método para desativar jogador
bool Jogodado::desativaPlayer()
{
  bool maior = false;

  int j=0;
  while(!m_jogadores[j]->isAtivo()) j++;
  Jogador * Maior = m_jogadores[j];

  for (int i = j+1; i < m_total_jogadores; ++i)
  {
    if (m_jogadores[i]->isAtivo())
    {
      if(Maior->getPontos() < Jogador::valor_maximo || m_jogadores[i]->getPontos() == Maior->getPontos())
      {
        maior=true;
      }
      if (m_jogadores[i]->getPontos() > Jogador::valor_maximo)
      {
        Maior = m_jogadores[i];
        maior = false;
      }
    }
  }
  if (!maior){
    Maior->desativar();
    m_ativos--;
    return true;
  }
  return false;
}

//Decide o vencedor da rodada
bool Jogodado::decide_Vencedor()
{
  bool maior = false;
  int j=0;
  while(!m_jogadores[j]->isAtivo()) j++;
  Jogador * Mais_prox = m_jogadores[j];
  for(int i=j+1; i<m_total_jogadores; i++)
  {
    if(m_jogadores[i]->isAtivo())
    {
      if(Mais_prox->getPontos() < Jogador::valor_maximo || Mais_prox->getPontos() == Jogador::valor_maximo)
      {
        if(m_jogadores[i] == Mais_prox)
        {
          maior = true;
        }
        if(Mais_prox->getPontos() == Jogador::valor_maximo)
        {
          maior=false;
        }
        if(m_jogadores[i]->getPontos() > Mais_prox->getPontos())
        {
          if(m_jogadores[i]->getPontos()< Jogador::valor_maximo|| m_jogadores[i]->getPontos() == Jogador::valor_maximo)
          {
            maior = false;
            Mais_prox = m_jogadores[i];
          }
          else
          {
            m_jogadores[i]->desativar();
            m_ativos--;
          }
        }
      }
      else
      {
        m_jogadores[j]->desativar();
        m_ativos--;
        Mais_prox=m_jogadores[i];
        maior = false;
      }
    }
  }
  if(!maior)
  {
    m_vencedor=Mais_prox;
    return true;
  }
  return false;
}

//Método para imprmir dados da rodada
void Jogodado::imprime_dados_rodada()
{
  cout<<"Rodada "<< m_rodada << ": ";
	for (int i = 0; i < m_total_jogadores; i++)
	{
		 cout << m_jogadores[i];
  }
  cout << endl;
}

//Método para imprimir vencedor da rodada
void Jogodado::imprimeVencedor()
{
  bool winners=false;
  int j=0;
  while(!m_jogadores[j]->isAtivo()) j++;
  Jogador * Winner = m_jogadores[j];

  for(int i=j+1; i<m_total_jogadores; i++)
  {
    if(m_jogadores[i]->isAtivo())
    {
      if(Winner==m_jogadores[i])
      {
        winners=true;
      }
    }
  }
  if(!winners)
  {
    if(m_vencedor->isAtivo()){
    cout << "O vencedor da Rodada foi : " << getVencedor()->getNome() << "  com um total de : "  << getVencedor()->getPontos() << endl;
    }
  }
  else
  {
    cout << "Mais de um jogador obteve o mesmo resultado e o maior da competição!" << endl;
  }
}

//Método que verifica se o jogo chegou ao final ou não
bool Jogodado::verifica_fim()
{
  bool fim=false;
  int somacaracter=0;
  for(int i=0;i<m_total_jogadores;i++)
  {
    if(m_jogadores[i]->isAtivo())
    {
      if(m_jogadores[i]->getDecisao() == 'N')
      {
        somacaracter+=78;
      }
    }
  }
  if((m_ativos*78)==somacaracter)
  {
    fim=true;
  }
  else
  {
    fim=false;
  }
  if(fim)
  {
    return false;
  }
  return true;
}

//Método que imprime o Vencedor do Jogo
void Jogodado::imprimeVencedor_fim()
{
  bool winners=false;
  int j=0;
  while(!m_jogadores[j]->isAtivo()) j++;
  Jogador * Winner = m_jogadores[j];

  for(int i=j+1; i<m_total_jogadores; i++)
  {
    if(m_jogadores[i]->isAtivo())
    {
      if(Winner==m_jogadores[i])
      {
        winners=true;
      }
    }
  }
  if(!winners)
  {
    if(m_vencedor->isAtivo()){
    cout << "O vencedor do Jogo foi : " << getVencedor()->getNome() << "  com um total de : "  << getVencedor()->getPontos() << endl;
    }
  }
  else
  {
    cout << "Mais de um jogador obteve o mesmo resultado e o maior da competição!" << endl;
  }
}
