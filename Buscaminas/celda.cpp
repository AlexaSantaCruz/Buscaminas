#include "getCelda.h"



CCelda::CCelda(char vX, char vY):
	x(vX),
	y(vY)
{
	
}

void CCelda::setMina()
{
	esMina = 1;
}

bool CCelda::getMina() {
	return esMina;
}

int CCelda::getMinasAlrededor() {
	return minasAlrededorNum;
}

bool CCelda:: estaAbierto() {
	return abierto;
}

bool CCelda::abrir(std::vector<CCelda>&vCelda) {
	if (0==abierto) {
		abierto = 1;
		if (0==esMina && 0== minasAlrededorNum) {
			for (int i = -1; i < 2;i++) {
				for (int j = -1; j < 2; j++) {
					
					if ((0 == i && 0 == j) || (0 > i + x || 0 > j + y || columnas == i + x || filas == j + y))
						continue;


					getCelda(i + x, j + y, vCelda)->abrir(vCelda);
				}
			}

		}
		return esMina;
		}

	return 0;
}

void CCelda::minasAlrededor(std::vector<CCelda>& vCelda) {
	minasAlrededorNum = 0;
	if (!esMina) {
		for (int a = -1; a < 2; a++)
		{
			for (int b = -1; b < 2; b++)
			{
				if ((0 == a && 0 == b) || (0 > a + x || 0 > b + y || columnas == a + x || filas == b + y))
				{
					continue;
				}

				if (1 == getCelda(a + x, b + y, vCelda)->getMina())
				{
					 minasAlrededorNum++; 
				}
			}
		}
	}


}

void CCelda::reset() {
	esMina = 0;
	abierto = 0;

}