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
const int ZERO = 0;

int main()
{
	Elements llistat;
	Player jugador(llistat);
	std::string input1;
	std::string input2;
	std::string firstWord;
	std::string secondWord;
	int number1;
	int number2;
	// El joc continuar� fins el moment en el que el jugador obtingui la m�zima puntuaci�, ho sigui, que descubreixi tots els elements.
	while(jugador.getScore()!=llistat.getNumComb()-llistat.getNumBasics())
	{
		// Demanem al jugador que introdueixi les dades.
		std::cin >> input1;
		// Comprovem que ha introdu�t el jugador:
		// En el cas de que sigui un nombre i aquest sigui a la llista...
		if(jugador.isNumber(input1) && atoi(input1.c_str())<jugador.dispElements.size() && atoi(input1.c_str())!= ZERO)
		{
			// Convertim l'string a enter.
			number1 = atoi(input1.c_str());
			// Demanem un altre nombre.
			std::cin >> input2;
			// Si aquest segon input tamb� es un nombre,s�n diferents i el nombre �s a la llista...
			if(jugador.isNumber(input2) && atoi(input2.c_str())<jugador.dispElements.size() && atoi(input2.c_str()) != ZERO)
			{
				// Convertim el segon nombre a enter
				number2 = atoi(input2.c_str());
				// Si s�n el mateix element...
				if (number1 == number2)
				{
					std::cout << "You can't combine one element!" << std::endl;
				}
				else
				{
					jugador.combination(number1, number2);
				}
			}
			else
			{
				std::cout << "Sorry, but that isn't an element." << std::endl;
				system("cls");
				jugador.printScore();
				jugador.printElements();
			}
		}
		// En el cas de que sigui una paraula...
		else if(!jugador.isNumber(input1))
		{
			if(input1=="sort")
			{
				jugador.sortElements();
			}
			else if(input1=="clean")
			{
				jugador.cleanElements();
			}
			else if(input1=="help")
			{
				jugador.printInterficie();
			}
			else if(input1=="info")
			{
				std::cin >> input2;
				if(jugador.isNumber(input2) && atoi(input2.c_str())<jugador.dispElements.size() && atoi(input2.c_str()) != ZERO)
				{
					number2 = atoi(input2.c_str());
					jugador.helpElements(number2);
				}
			}
			else if(input1=="delete")
			{
				std::cin >> input2;
				if(jugador.isNumber(input2) && atoi(input2.c_str())<jugador.dispElements.size() && atoi(input2.c_str()) != ZERO)
				{
					number2 = atoi(input2.c_str());
					jugador.deleteElement(number2);
				}
			}
			else if(input1=="add")
			{
				std::cin >> input2;
				if (input2 == "basics")
				{
					jugador.addBasics();
				}
				if(jugador.isNumber(input2) && atoi(input2.c_str())<jugador.dispElements.size() && atoi(input2.c_str()) != ZERO)
				{
					number2 = atoi(input2.c_str());
					jugador.addElement(number2);
				}
			}
			else
			{
				std::cout << "This command doesn't exist." << std::endl;
			}
		}
		std::cin.clear(); // clears all error state flags
		// extracts characters from the input buffer and discards them
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	}
	return 0;
}