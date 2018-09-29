#include <random>

#include "dado.h"

Dado::Dado(int lados):rd(), gen(rd()), dis(1, lados) {
	m_numlados = lados;
	m_valor = std::round(dis(gen));
}

int 
Dado::jogar() {
	m_valor = std::round(dis(gen));
	return m_valor;
}

int 
Dado::getValor() {
	return m_valor;
}

int 
Dado::getLados(){
	return m_numlados;
}