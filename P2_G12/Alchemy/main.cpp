#include <fstream>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
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
	// El joc continuarà fins el moment en el que el jugador obtingui la màzima puntuació, ho sigui, que descubreixi tots els elements.
	while(jugador.getScore()!=llistat.getNumComb()-llistat.getNumBasics())
	{
		// Demanem al jugador que introdueixi les dades.
		std::cin >> input1;
		// Comprovem que ha introduït el jugador:
		// En el cas de que sigui un nombre...
		if(jugador.isNumber(input1))
		{
		
		}
		// En el cas de que sigui una paraula...
		else
		{
		
		}
	}
	return 0;
}