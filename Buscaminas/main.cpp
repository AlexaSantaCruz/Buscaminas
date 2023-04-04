#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include <iostream>


#include "getCelda.h"

template<typename T>
constexpr const T& clamp(const T& v, const T& lo, const T& hi)
{
	return v < lo ? lo : v > hi ? hi : v;
}


int main()
{
	std:: cin >> columnas;
	std::cin >> filas;
	std::cin >> minas;
	std::cout << columnas + filas + minas;

	unsigned lag = 0;
	CPantalla objPantalla;
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(tamanioCelda * columnas * tamanioPantalla, tamanioPantalla * (alturaFuente + tamanioCelda * columnas)), "BUSCAMINAS", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, tamanioCelda * columnas, alturaFuente + tamanioCelda * filas)));




	while (window.isOpen()) {


		
			unsigned char mouseX = clamp(static_cast<int>(floor(sf::Mouse::getPosition(window).x / static_cast<float>(tamanioCelda * tamanioPantalla))), 0, columnas - 1);
			unsigned char mouseY = clamp(static_cast<int>(floor(sf::Mouse::getPosition(window).y / static_cast<float>(tamanioCelda * tamanioPantalla))), 0, filas - 1);


		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();

				break;
			}
			case sf::Event::KeyReleased:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Enter:
				{
					objPantalla.reinicio();
				}
				}

				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left:
				{

					objPantalla.abrirCeldas(mouseX, mouseY);

					break;
				}
				case sf::Mouse::Right:
				{
					//Aca implementar bandera
					//objPantalla.bandera(mouse_cell_x, mouse_cell_y);
				}
				}
			}
			
		}

		}
	
			window.clear();

			objPantalla.dibujar(window);
		
			window.display();

		}
		
		
	}

	

	



