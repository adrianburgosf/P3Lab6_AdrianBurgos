#include "BuscaMinas.h"

BuscaMinas::BuscaMinas (int dificultad) {
	this->tableroBombas = new Tablero(dificultad);
	switch (dificultad) {
		case 1: {
			this->casillas = 64-12;
			break;
		}
		case 2: {
			this->casillas = 100-25;
			break;
		}
		case 3: {
			this->casillas = 144-43;
			break;
		}
	}
	jugar();
}

void BuscaMinas::jugar() {
	int fila;
	int columna;
	bool flag = false;
	int opcion = menu();

	while (!flag && casillas-1 > tableroBombas->getDestapadas()) {
		switch (opcion) {
			case 1: {
				cout << endl << "Ingrese la fila: ";
				cin >> fila;
				cout << "Ingrese la columna: ";
				cin >> columna;
				if (fila < tableroBombas->getSize() && fila >= 0 && columna < tableroBombas->getSize() && columna >= 0) {
					flag = tableroBombas->destaparCasilla(fila,columna);
				} 
				else {
					cout << "Valores ingresados invalidos, vuelva a ingresar" << endl;
					while (fila < 0 || fila >= tableroBombas->getSize() || columna >= tableroBombas->getSize() || columna < 0) {
						cout << endl;
						cout << "Ingrese la fila: ";
						cin >> fila;
						cout << "Ingrese la columna: ";
						cin >> columna;
					}
					flag = tableroBombas->destaparCasilla(fila,columna);
				}
				break;
			}
			case 2: {
				cout << endl << "Ingrese la fila: ";
				cin >> fila;
				cout << "Ingrese la columna: ";
				cin >> columna;
				if (fila < tableroBombas->getSize() && fila >= 0 && columna < tableroBombas->getSize() && columna >= 0) {
					tableroBombas->marcarCasilla(fila, columna);
				} 
				break;
			}
			default:
				cout << "Opcion ingresada invalida";
		}
		
		if (!flag) {
			tableroBombas->imprimir();
			if (casillas-1 > tableroBombas->getDestapadas()) {
				opcion = menu();
			}
		}
	}
	if (flag == true) {
		cout << endl << "Tocaste una bomba, perdiste!";
	}
	else cout << endl <<"Ganaste!!!!";
}

int BuscaMinas::menu() {
	int opcion = 0;
	cout << "====== Que Desea Realizar? ==========" << endl
	     << "1) Destapar" << endl
	     << "2) Marcar" << endl
	     << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}

BuscaMinas::~BuscaMinas() {
	delete tableroBombas;
}