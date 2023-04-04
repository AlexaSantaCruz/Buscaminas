#pragma once
#include <vector>

class CCelda {
	//bool bandera;
	bool esMina;
	bool abierto;

	char x;
	char y;
	int minasAlrededorNum;


public:
	CCelda(char vX, char vY);
	void setMina();
	bool getMina();
	bool estaAbierto();

	void minasAlrededor(std::vector<CCelda>&vCelda);
	int getMinasAlrededor();
	bool abrir(std::vector<CCelda>& vCelda);
	void reset();



};