#include "Player Manager.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Inicialitzem el vector amb els elements b�sics, la puntuaci� i la variable de classe elements de Player.
Player::Player(Elements &elements) :score{ 0 }, dispElements({ "ZERO","Air", "Earth", "Fire", "Water" }), discoveredElements({ "Air", "Earth", "Fire", "Water" }),myElements{ elements } 
{
	printInterficie();
	std::cout << std::endl;
	for(int i=FIRST_ELEMENT;i<=myElements.getNumBasics();i++)
	{
		std::cout << i << " :" << dispElements[i] << std::endl;
	}
}

void Player::printInterficie()
{
	// Imprimim l'interf�cie.
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
}

int Player::getScore()
{
	return score;
}

bool Player::isNumber(std::string input)
{
	int numCounter = 0;
	for(int i=0;i<=input.size();i++)
	{
		// Comprovem si cada un dels car�cters de l'input s�n una lletra.
		if((input[i]<='A' && input[i]>='Z') || (input[i]<='a' && input[i]>='z'))
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
}

void Player::addElement(int numberElement)
{
	if ( numberElement <=dispElements.size())
	{
		dispElements.push_back(dispElements[numberElement]);
	}
}

void Player::combination(int n1,int n2)
{
	// Trobem els dos elements que pertanyen als dos nombres que el jugador ha introdu�t.
	std::string firstElement=dispElements[n1];
	std::string secondElement=dispElements[n2];
	// Eliminem els dos elements que hem utilitzat per la combinaci� de la llista.
	dispElements.erase(dispElements.begin()+n1);
	dispElements.erase(dispElements.begin()+n2);
	// En la posici� del primer element utilitzat en la combinaci�, i fiquem l'element resultant d'aquesta.
	dispElements[n1] = myElements.getElementMap()[{firstElement, secondElement}];
	// Ara comprovem si ja haviem fet aquesta combinaci� en una altre ocasi� i
	// si no es aix� el bucle s'activa.
	if(!std::binary_search(discoveredElements.begin(),discoveredElements.end(),dispElements[n1]))
	{
		// Afegim el nou element a la llista d'elements ja descoberts.
		discoveredElements.push_back(dispElements[n1]);
		// Per �ltim, com que hem descobert una nova combinaci�, augmentem la puntuaci�.
		score++;
	}
}



