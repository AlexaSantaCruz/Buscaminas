#pragma once
#include <vector>

class CCelda {
	bool bandera;
	bool esMina;
	bool abierto;

	int x;
	int y;
	int minasAlrededorNum;


public:
	CCelda() = default;
	CCelda(int vX, int vY);
	void setMina();
	bool getMina();
	bool estaAbierto();

	void minasAlrededor(std::vector<CCelda>& vCelda);
	int getMinasAlrededor();
	bool abrir(std::vector<CCelda>& vCelda);
	void reset();
	void banderas();
	bool getBandera();


};