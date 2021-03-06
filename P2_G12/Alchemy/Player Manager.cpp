#include "Player Manager.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

// Inicialitzem el vector amb els elements b�sics, la puntuaci� i la variable de classe elements de Player.
Player::Player(Elements &elements) :score{ 0 }, dispElements({ "ZERO","Air", "Earth", "Fire", "Water" }), discoveredElements({ "Air", "Earth", "Fire", "Water" }),myElements{ elements } 
{
	printInterficie();
}

void Player::printInterficie()
{
	// Imprimim l'interf�cie.
	system("cls");
	std::cout << "--------------" << std::endl << "FULLENTI ALCHEMIST" << std::endl << "--------------" << std::endl;
	std::cout <<
	"- Enter two numbers of your elements list to combine them." << std::endl <<
	"- Enter the word 'add' and the number of an element to add a new instance of that element. " << std::endl <<
	"- Enter 'add basics' to add new instances of the 4 basic elements." << std::endl <<
	"- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl <<
	"- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl <<
	"- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl <<
	"- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl <<
	"- Enter the word 'help' to show this tutorial." << std::endl <<
	"Your current score: " << score << std::endl << std::endl <<
	"Your have these elements:" << std::endl;	
	printElements();
}

int Player::getScore()
{
	return score;
}

bool Player::isNumber(std::string input)
{
	int numCounter = 0;
	for(int i=0;i<input.size();i++)
	{
		// Comprovem si cada un dels car�cters de l'input s�n una lletra.
		if((input[i]>='0' && input[i]<='9'))
		{
			numCounter++;
		}
	}
	return numCounter == input.size();
}

void Player::addBasics()
{
	// Afegim els elements b�sics a la llista.
	dispElements.push_back("Air");
	dispElements.push_back("Earth");
	dispElements.push_back("Fire");
	dispElements.push_back("Water");
	system("cls");
	printScore();
	printElements();
}

void Player::addElement(int numberElement)
{
	if ( numberElement <=dispElements.size())
	{
		dispElements.push_back(dispElements[numberElement]);
	}
	system("cls");
	printScore();
	printElements();
}

void Player::combination(int n1,int n2)
{
	// Netejem la consola.
	system("cls");
	// Trobem els dos elements que pertanyen als dos nombres que el jugador ha introdu�t.
	std::string firstElement = dispElements[n1];
	std::string secondElement = dispElements[n2];
	bool wasFirst;
	// Si la combinaci� existeix...
	if (myElements.isCombination(dispElements[n1],dispElements[n2]))
	{
		// Eliminem els dos elements que hem utilitzat per la combinaci� de la llista.
		if (n2>n1)
		{
			dispElements.erase(dispElements.begin() + n2);
			dispElements.erase(dispElements.begin() + n1);
		}
		else
		{
			dispElements.erase(dispElements.begin() + n1);
			dispElements.erase(dispElements.begin() + n2);
		}
		// Fiquem l'element resultat de la combinaci� al final de la llista.
		dispElements.push_back(myElements.getElementMap()[{firstElement, secondElement}]);
		// Ara comprovem si ja haviem fet aquesta combinaci� en una altre ocasi� i
		// si no es aix� el bucle s'activa.
		if (!discoveredElement(dispElements[dispElements.size()-FIRST_ELEMENT]))
		{
			std::cout << "You discovered " << dispElements[dispElements.size() - FIRST_ELEMENT] << std::endl << std::endl;
			// Afegim el nou element a la llista d'elements ja descoberts.
			discoveredElements.push_back(dispElements[dispElements.size()-FIRST_ELEMENT]);
			// Per �ltim, com que hem descobert una nova combinaci�, augmentem la puntuaci�.
			score++;
		}
	}
	// En cas contrari...
	else
	{
		std::cout << "You can't combine this two elements." << std::endl << std::endl;
	}
	printScore();
	printElements();
}

void Player::printScore()
{
	std::cout << "Your score is: " << score << std::endl;
}

void Player::printElements()
{
	for(int i=FIRST_ELEMENT;i<dispElements.size();i++)
	{
		std::cout << i << ": " << dispElements[i] << std::endl;
	}
}

void Player::sortElements()
{
	sort(dispElements.begin()+FIRST_ELEMENT, dispElements.end());
	system("cls");
	printScore();
	printElements();
}

void Player::cleanElements()
{
	for(int i=FIRST_ELEMENT;i<=dispElements.size()-FIRST_ELEMENT;i++)
	{
		for(int j=FIRST_ELEMENT;j<=dispElements.size()-FIRST_ELEMENT;j++)
		{
			if(i!=j && dispElements[i]==dispElements[j])
			{
				dispElements.erase(dispElements.begin()+i);
				j--;
			}
		}
	}
	system("cls");
	printScore();
	printElements();
}

void Player::helpElements(int inp)
{
	std::string str = "https://en.wikipedia.org/wiki/";
	str += dispElements[inp];
	LPSTR url = const_cast<char *>(str.c_str());
	ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
}

void Player::deleteElement(int inp)
{
	dispElements.erase(dispElements.begin()+inp);
	system("cls");
	printScore();
	printElements();
}

bool Player::discoveredElement(std::string inp)
{
	for(int i=FIRST_ELEMENT;i<=discoveredElements.size()-FIRST_ELEMENT;i++)
	{
		if(discoveredElements[i]==inp)
		{
			return true;
		}
	}
	return false;
}


