#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include <iostream>


#include "facil.h"
#include "filasColumnas.h"
#include "celda.h"
#include "pantalla.h"



int main()
{

	int dificultad;
	std::cin >> dificultad;

	int columna=0;
	int fila=0;
	int mina=0;
	CPantalla objPantalla;
	switch (dificultad)
	{
	case 1:
		columna = 8;
		fila = 8;
		mina = 8;

		dificultadFacil(fila, columna, mina);
		break;

	case 2:
		columna = 10;
		fila = 10;
		mina = 10;
		dificultadFacil(fila, columna, mina);
		break;
	default:
		break;
	}
	
	}

	

	



