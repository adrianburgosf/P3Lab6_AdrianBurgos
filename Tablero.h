#ifndef TABLERO_H
#define TABLERO_H

#include <stdlib.h>
#include <time.h>  
#include <cstddef>

#include "CasillaBuscaMinas.h"

class Tablero
{
	public:
		Tablero(int dificultad);
		~Tablero();
		bool destaparCasilla(int, int);
		int calcularBombas(int,int);
		void marcarCasilla(int,int);
		void imprimirBombas();
		void imprimir();
		void llenarBombas(int,int);
		int getSize();
		int getDestapadas();
	private: 
		CasillaBuscaMinas*** tablero;
		int size;	
		int destapadas;
	protected:
};

#endif