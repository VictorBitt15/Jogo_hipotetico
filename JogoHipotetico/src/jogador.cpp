#include "jogador.h"
#include "dado.h"

Jogador::Jogador(const string nome_):m_nome(nome_),m_pontos(0),m_ativo(true){
  m_decisao='U';
}

Jogador::~Jogador(){}

//Getters

int Jogador::getPontos()
{
  return m_pontos;
}

string Jogador::getNome()
{
  return m_nome;
}

bool Jogador::isAtivo()
{
  return m_ativo;
}

char Jogador::getDecisao()
{
  return m_decisao;
}
//Fim Getters

//Método de desativar jogador
void Jogador::desativar()
{
  m_ativo=false;
}

//Método de Jogar os dados
void Jogador::jogar(Dado &d1, Dado &d2)
{
  m_pontos+= d1.jogar() + d2.jogar();
}

void Jogador::alterar_decisao(const char decisao_)
{
  m_decisao=decisao_;
}

//Sobrecarga operador <<
std::ostream& operator<< (std::ostream &o, Jogador * j)
{
  if(!j->isAtivo())
  {
   cout << "*";
  }
  cout<<j->getNome()<<"("<<j->getPontos()<<") ";
  return o;
}

//Sobrecarga operador ==
bool Jogador::operator== (Jogador * player)
{
  if(player->getPontos() == m_pontos)
  {
    return true;
  }
  return false;
}
