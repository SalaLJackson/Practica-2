#include "Element_List.h"
#include <fstream>
#include <iostream>
#include <string>

Elements::Elements()
{
	std::ifstream ficherElements("elements.dat"); // Obrim el fitxer d'elements per a inciar la lectura.
	std::string element;
	std::string firstKey;
	std::string secondKey;
	std::string line; // Array en el que guardarem el que llegim en cada iteraci�.
	if (ficherElements.is_open())
	{
		// Bucle que s'activar� mentres que no haguem arribat a l'EOF.
		while (getline(ficherElements, line))
		{
			// Contador que utilitzarem per a saber quants car�cters ja hem processat en cada l�nia.
			int counter = 0;
			// Amb aquest for, guardarem els car�cters de "elements.dat" fins que trobem el car�cter '=', moment en que passarem a borrar l'�ltim car�cter
			// introdu�t en elements (que ser� un espai) i aix� obtindrem l'element d'aquella l�nia.
			for (int i = 0; i != line.find('='); i++)
			{
				element.push_back(line[i]);
				counter++;
			}
			element.pop_back(); // Eliminem l'�ltim element de la fila (espai).
			// Amb aquest for, guardarem els car�cters fins que trobem el car�cter '+', aix� obtenint un dels elements necessaris per a la combinaci�.
			for (int i = counter; i != line.find('+'); i++)
			{
				if (line[i] != ' ' && line[i] != '=')
				{
					firstKey.push_back(line[i]);
				}
				counter++;
			}
			// I per �ltim, un altre for per a guardar el segon element de la combinaci�.
			for (int i = counter; i < line.size(); i++)
			{
				if (line[i] != '+' && line[i] != ' ')
				{
					secondKey.push_back(line[i]);
					counter++;
				}
			}
			elementMap.insert({ {firstKey,secondKey},element });
			element.erase();
			firstKey.erase();
			secondKey.erase();
		}
		ficherElements.close(); // Tanquem el fitxer dels elements.
	}
	// En cas de que el fitxer no sigui obert o b� el nombre d'elements nosigui correcte,
	//el programa s'aturar� amb system("pause").
	else if (!ficherElements.is_open() || elementMap.size()!=NUM_COMBINATIONS)
	{
		std::cout << "Combinacions no cargades correctament";
		system("pause");
	}
}

int Elements::getNumBasics()
{
	return NUM_BASICS;
}

int Elements::getNumComb()
{
	return NUM_COMBINATIONS;
}

std::unordered_map<Elements::elements, std::string, Elements::elements> Elements::getElementMap()
{
	return elementMap;
}