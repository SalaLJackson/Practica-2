#include <fstream>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <Windows.h>
#include "Element_List.h"
#include "Player Manager.h"

int main()
{
	Elements llistat;
	Player jugador(llistat);
	std::string input;
	
	int number;
	// El joc continuarà fins el moment en el que el jugador obtingui la màzima puntuació, ho sigui, que descubreixi tots els elements.
	while(jugador.getScore()!=llistat.getNumComb()-llistat.getNumBasics())
	{
		// Demanem al jugador que introdueixi les dades.
		std::cin >> input;
		// Comprovem que ha introduït el jugador:
		// En el cas de que sigui un nombre...
		if(jugador.isNumber(input))
		{
			// Convertim l'string a enter.
			number = atoi(input.c_str);
			// Demanem un altre nombre.
			std::cin >> input;
			// Si aquest segon input també es un nombre:
			if(jugador.isNumber(input))
			{
				
			}
		}
		// En el cas de que sigui una paraula...
		else
		{
		
		}
	}
	return 0;
}