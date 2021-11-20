#include <iostream>
#include "Tablero.h"

Tablero::Tablero (int dificultad) {
	this->destapadas = 0;
	switch (dificultad) {
		case 1: {
			this -> size = 8;
			this->tablero = new CasillaBuscaMinas**[8];
			for(int i = 0; i < 8; i++) {
				tablero[i] = new CasillaBuscaMinas*[8];
			}
			llenarBombas (12,8);
			imprimir();
			std::cout << std::endl;
			imprimirBombas();
			break;
		}
		case 2: {
			this -> size = 10;
			this->tablero = new CasillaBuscaMinas**[10];
			for(int i = 0; i < 10; i++) {
				tablero[i] = new CasillaBuscaMinas*[10];
			}
			llenarBombas (25,10);
			imprimir();
			std::cout << std::endl;
			imprimirBombas();
			break;
		}
		case 3: {
			this -> size = 12;
			this->tablero = new CasillaBuscaMinas**[12];
			for(int i = 0; i < 12; i++) {
				tablero[i] = new CasillaBuscaMinas*[12];
			}
			llenarBombas (43,12);
			imprimir();
			std::cout << std::endl;
			imprimirBombas();
			break;
		}
	}
}

int Tablero::getSize() {
	return this->size;
}

int Tablero::getDestapadas() {
	return destapadas;
}

void Tablero::llenarBombas (int bombas, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tablero[i][j] = new CasillaBuscaMinas();
		}
	}
	int contador = 0;
	while (contador <= bombas) {
		int x = rand() % size;
		int y = rand() % size;
		if (!tablero[x][y]->getEsBomba()) {
			tablero[x][y]->setEsBomba(true);
			contador++;
		}
	}
}

void Tablero::imprimir() {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			std::cout << tablero[i][j]->getDisplay() << " ";
		}
		std::cout << std::endl;
	}
}

void Tablero::imprimirBombas() {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (tablero[i][j]->getEsBomba()) {
				std::cout << "# ";
			} else std::cout << tablero[i][j]->getDisplay() << " ";

		}
		std::cout << std::endl;
	}
}

bool Tablero::destaparCasilla(int fila, int columna) {
	if (tablero[fila][columna]->getEsBomba()) {
		return true;
	}
	tablero[fila][columna]->setDisplay(48+calcularBombas(fila, columna));
	tablero[fila][columna]->setDescubierta(true);
	this->destapadas++;

	//Abajo
	if (fila+1 >= 0 && fila+1 < this->size) {
		if (tablero[fila+1][columna]->getEsBomba() == false && tablero[fila+1][columna]->getDescubierta() == false) {
			destaparCasilla(fila+1, columna);
		}
	}
	//Arriba
	if (fila-1 >= 0 && fila-1 < this->size) {
		if (tablero[fila-1][columna]->getEsBomba() == false && tablero[fila-1][columna]->getDescubierta() == false) {
			destaparCasilla(fila-1, columna);
		}
	}
	//Izquierda
	if (columna-1 >= 0 && columna-1 < this->size) {
		if (tablero[fila][columna-1]->getEsBomba() == false && tablero[fila][columna-1]->getDescubierta() == false) {
			destaparCasilla(fila, columna-1);
		}
	}
	//Derecha
	if (columna+1 >= 0 && columna+1 < this->size) {
		if (tablero[fila][columna+1]->getEsBomba() == false && tablero[fila][columna+1]->getDescubierta() == false) {
			destaparCasilla(fila, columna+1);
		}
	}
	return false;
}

int Tablero::calcularBombas(int fila, int columna) {
	int bombas = 0;
	for (int i = fila-1; i <= fila+1; i++) {
		if (i >= 0 && i < this->size) {
			for (int j = columna-1; j <= columna+1; j++) {
				if (j >= 0 && j < this->size) {
					if (tablero[i][j]->getEsBomba() == true) {
						bombas++;
					}
				}
			}
		}
	}
	return bombas;
}

void Tablero::marcarCasilla(int fila,int columna) {
	tablero[fila][columna]->setMarcada(true);
	tablero[fila][columna]->setDisplay('X');
}

Tablero::~Tablero() {
	if (this->tablero != NULL) {
		for(int i = 0; i < this->size; i++) {
			delete[] tablero[i];
		}
		delete[] tablero;
		tablero = NULL;
	}
}