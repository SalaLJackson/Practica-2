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
	std::string input1;
	std::string input2;
	int number1;
	int number2;
	// El joc continuarà fins el moment en el que el jugador obtingui la màzima puntuació, ho sigui, que descubreixi tots els elements.
	while(jugador.getScore()!=llistat.getNumComb()-llistat.getNumBasics())
	{
		// Demanem al jugador que introdueixi les dades.
		std::cin >> input1;
		// Comprovem que ha introduït el jugador:
		// En el cas de que sigui un nombre i aquest sigui a la llista...
		if(jugador.isNumber(input1) && atoi(input1.c_str())<jugador.dispElements.size())
		{
			// Convertim l'string a enter.
			number1 = atoi(input1.c_str());
			// Demanem un altre nombre.
			std::cin >> input2;
			// Si aquest segon input també es un nombre,són diferents i el nombre és a la llista...
			if(jugador.isNumber(input2) && input1!=input2 && atoi(input2.c_str())<jugador.dispElements.size())
			{
				// Convertim el segon nombre a enter
				number2 = atoi(input2.c_str());
				jugador.combination(number1,number2);
			}
			// Si són el mateix nombre..
			else if(input1==input2)
			{
				std::cout << "You can't combine the same element!" << std::endl;
			}
		}
		// En el cas de que sigui una paraula...
		else if(!jugador.isNumber(input1))
		{
		
		}
	}
	return 0;
}