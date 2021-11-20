#ifndef CASILLABUSCAMINAS_H
#define CASILLABUSCAMINAS_H

class CasillaBuscaMinas
{
	public:
		CasillaBuscaMinas();
		bool getEsBomba();
		void setEsBomba(bool);
		bool getDescubierta();
		void setDescubierta(bool);
		char getDisplay();
		void setDisplay(char);
		bool getMarcada();
		void setMarcada(bool);
		
	private:
		bool esBomba;
		bool descubierta;
		char display;
		bool marcada;
	protected:
};

#endif