#include <iostream>
#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H

#include "Tablero.h"

using std::cout;
using std::cin;
using std::endl;

class BuscaMinas
{
	public:
		BuscaMinas(int);
		~BuscaMinas();
		void jugar();
		int menu();
	private: 
		Tablero* tableroBombas;
		int casillas;
	protected:
};

#endif