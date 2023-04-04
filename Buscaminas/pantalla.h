#pragma once
#include <vector>
#include "getCelda.h"
#include <random>
#include <SFML/Graphics.hpp>

class CPantalla {
	std::default_random_engine random_engine;

	std::random_device random_device;

	std::vector<CCelda> celdas;
	char perdiste;

	bool primerClickJuego;

public:
	CPantalla();

	void dibujar(sf::RenderWindow& vVentana);
	void cubrirCeldas(sf::RenderWindow vVentana);
	void reinicio();
	void abrirCeldas(char vX, char vY);
};