#include "Element_List.h"
#include <fstream>
#include <iostream>

Elements::Elements()
{
	std::string element;
	std::string comb;
	std::ifstream ficherElements("elements.dat"); // Obrim el fitxer d'elements per a inciar la lectura.
	
	ficheroElementos.close(); // Tanquem el fitxer dels elements.
}