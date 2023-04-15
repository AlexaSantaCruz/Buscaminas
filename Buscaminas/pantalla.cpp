#include "getCelda.h"
#include <iostream>


CPantalla::CPantalla():

	perdiste(1),
	random_engine(random_device())
{	


	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			//para evitar que las celdas tengan valores mas altos de los que se esperan
			celdas.push_back(CCelda(j, i));
		}
	}
	reinicio();

}

void CPantalla::reinicio() {
	if (0 != perdiste) {
		perdiste = 0;
		for (CCelda&celda:celdas) {
			celda.reset();
		}
	}
	
}

void CPantalla::abrirCeldas(char vX, char vY) {
	

	if (0==primerClickJuego) {
		std::uniform_int_distribution<short> enX(0, columnas - 1);
		std::uniform_int_distribution<short> enY(0, filas - 1);
		primerClickJuego = 1;

		for (int a = 0; a < minas; a++)
		{
			char mine_x = static_cast<char>(enX(random_engine));
			char mine_y = static_cast<char>(enY(random_engine));

			if (1 == getCelda(mine_x, mine_y, celdas)->getMina() || (vX == mine_x && vY == mine_y))
			{
				a--;
			}
			else
			{
				getCelda(mine_x, mine_y, celdas)->setMina();
			}
		}

		for (CCelda& cell : celdas)
		{
			cell.minasAlrededor(celdas);
		}
	}

	if (0 == perdiste/* && 0 == getCelda(vX, vY, celdas)->get_is_flagged()*/)
	{
		if (1 == getCelda(vX, vY, celdas)->abrir(celdas))
		{
			perdiste = -1;
			printf("perdiste");

		}
		else
		{
			int total_closed_cells = 0;

			for (CCelda& cell : celdas)
			{
				total_closed_cells += 1 - cell.estaAbierto();
			}

			if (minas == total_closed_cells)
			{
				perdiste = 1; 
				printf("ganaste");

				
			}
		}

	}
}

void CPantalla::dibujar(sf::RenderWindow& vVentana) {
	sf::RectangleShape formaCelda(sf::Vector2f(tamanioCelda - 1, tamanioCelda - 1));
	sf::Sprite botonesabiertosSprite;
	sf::Texture texturaIconos;
	texturaIconos.loadFromFile("imagenes/tiles16Bits.png");
	botonesabiertosSprite.setTexture(texturaIconos);


	for (int i = 0; i < columnas; i++) {

		for (int j = 0; j < filas; j++) {


			formaCelda.setPosition(static_cast<float>(tamanioCelda * i), static_cast<float>(tamanioCelda * j));
			
			if (getCelda(i, j, celdas)->estaAbierto()) {
				int minasAlr = getCelda(i, j, celdas)->getMinasAlrededor();
				formaCelda.setFillColor(sf::Color(128, 128, 128));
				vVentana.draw(formaCelda);

				if (1 == getCelda(i, j, celdas)->getMina()) {
					formaCelda.setFillColor(sf::Color(219, 0, 0)); //color para minas
					formaCelda.setPosition(tamanioCelda * i, tamanioCelda * j);

					vVentana.draw(formaCelda);
				}


				if (0 < minasAlr) {
					botonesabiertosSprite.setPosition(static_cast<float>(tamanioCelda * i), static_cast<float>(tamanioCelda * j));
					botonesabiertosSprite.setTextureRect(sf::IntRect(tamanioCelda * minasAlr, 0, tamanioCelda, tamanioCelda));

					vVentana.draw(botonesabiertosSprite);
				}
			}
			else {
				formaCelda.setFillColor(sf::Color(192, 192, 192));
				vVentana.draw(formaCelda);

			}

		
		
		}
	}
	if (perdiste) {
		for (unsigned char i = 0; i < columnas; i++) {

			for (unsigned char j = 0; j < filas; j++) {

				if (1 == getCelda(i, j, celdas)->getMina()) {
					formaCelda.setFillColor(sf::Color(219, 0, 0)); //color para minas
					formaCelda.setPosition(tamanioCelda * i, tamanioCelda * j);

					vVentana.draw(formaCelda);

				}
				else {
					for (CCelda& celda : celdas) {
						celda.minasAlrededor(celdas);
					}
					unsigned char minasAlr = getCelda(i, j, celdas)->getMinasAlrededor();
					formaCelda.setFillColor(sf::Color(128, 128, 128));
					formaCelda.setPosition(tamanioCelda * i, tamanioCelda * j);

					vVentana.draw(formaCelda);

					if (0 < minasAlr) {
						botonesabiertosSprite.setPosition(static_cast<float>(tamanioCelda * i), static_cast<float>(tamanioCelda * j));
						botonesabiertosSprite.setTextureRect(sf::IntRect(tamanioCelda * minasAlr, 0, tamanioCelda, tamanioCelda));

						vVentana.draw(botonesabiertosSprite);
					}
				}

				formaCelda.setPosition(tamanioCelda * i, tamanioCelda * j);

			}
		}
	}
}

void CPantalla::actualizarDimensiones(int newColumns, int newRows, int mina){
	// Crear un nuevo vector con la nueva capacidad deseada.
	std::vector<CCelda> newCeldas(newColumns * newRows);

// Crear una nueva celda para cada índice en el nuevo vector.
for (int i = 0; i < newRows; i++) {
	for (int j = 0; j < newColumns; j++) {
		newCeldas[i * newColumns + j] = CCelda(j, i);
	}
}

// Calcular el número de minas adyacentes para cada celda en el nuevo vector
for (CCelda& cell : newCeldas) {
	cell.minasAlrededor(newCeldas);
}

// Liberar la memoria del vector anterior.
celdas.clear();

// Asignar el nuevo vector a la variable del vector.
celdas = newCeldas;

// Actualizar los tamaños de la pantalla y de las celdas.
columnas = newColumns;
filas = newRows;

}