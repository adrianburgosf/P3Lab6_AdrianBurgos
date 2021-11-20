#include "CasillaBuscaMinas.h"

CasillaBuscaMinas::CasillaBuscaMinas () {
	setDisplay('-');
	setEsBomba(false);
	setDescubierta(false);
	setMarcada(false);
}

char CasillaBuscaMinas::getDisplay() {
	return this->display;
}
void CasillaBuscaMinas::setDisplay(char x) {
	this->display = x;
}

bool CasillaBuscaMinas::getDescubierta() {
	return this->descubierta;
}
void CasillaBuscaMinas::setDescubierta(bool flag) {
	this->descubierta = flag;
}

bool CasillaBuscaMinas::getEsBomba() {
	return this->esBomba;
}
void CasillaBuscaMinas::setEsBomba(bool flag) {
	this->esBomba = flag;
}

bool CasillaBuscaMinas::getMarcada() {
	return this->marcada;
}
void CasillaBuscaMinas::setMarcada(bool flag) {
	this->marcada = flag;
}
