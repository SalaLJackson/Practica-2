#include "Element_List.h"
#include <fstream>
#include <iostream>
#include <string>

const int MAX_CHAR = 250;

Elements::Elements()
{
	std::ifstream ficherElements("elements.dat"); // Obrim el fitxer d'elements per a inciar la lectura.
	std::string element;
	std::string key;
	char storeArray[MAX_CHAR]; // Array en el que guardarem el que llegim en cada iteració.
	int counter=0;
	// Bucle que s'activarà mentres que no haguem arribat a l'EOF.
	while (!ficherElements.eof())
	{
		while (ficherElements.get!='=')
		{
			storeArray[counter] = ficherElements.get;
		}
	}
	ficherElements.close(); // Tanquem el fitxer dels elements.
}