#include "getCelda.h"



CCelda* getCelda(char vX, char vY, std::vector<CCelda>& vCelda) {
	return &vCelda[vX + columnas * vY];

}