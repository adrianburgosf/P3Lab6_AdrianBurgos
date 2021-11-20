#include <iostream>
#include <stdlib.h> 
#include <time.h>  

#include "BuscaMinas.h"
#include "Tablero.h"
#include "CasillaBuscaMinas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::endl;
using std::cin;

int dificultad();

int main(int argc, char** argv) {
	srand (time(NULL));
	
	int difi = dificultad();
	
	BuscaMinas* buscaMinas;
	switch (difi) {
		case 1: {
			buscaMinas = new BuscaMinas(difi);
			break;
		}
		case 2: {
			buscaMinas = new BuscaMinas(difi);
			break;
		}
		case 3: {
			buscaMinas = new BuscaMinas(difi);
			break;
		}
	}
	delete buscaMinas;
	return 0;
}

int dificultad() {
	int opcion = 0;
	cout << "===========Dificultad===========" << endl
	     << "1) Facil" << endl
	     << "2) Normal" << endl
	     << "3) Dificil" << endl
		 << "Ingrese su opcion: ";
	cin >> opcion;
	cout << endl;
	return opcion;
}
