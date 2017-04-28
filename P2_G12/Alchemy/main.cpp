#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include "Element_List.h"
#include "Player Manager.h"

int main()
{
	Elements llistat;
	Player jugador(llistat);
	// El joc continuarà fins el moment en el que el jugador obtingui la màzima puntuació, ho sigui, que descubreixi tots els elements.
	while(jugador.getScore()!=llistat.getNumComb-llistat.getNumBasics)
	{
	
	}
	return 0;
}