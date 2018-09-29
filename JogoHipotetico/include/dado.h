#ifndef _DADO_H_
#define _DADO_H_

#include <random>

class Dado {
	private:
		int m_valor;
		int m_numlados;
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;
	public:
		Dado (int lados);
		int jogar();
		int getValor();
		int getLados();
};

#endif
