#include "Player Manager.h"
#include <iostream>
#include <vector>
#include <string>

Player::Player() :score{0},dispElements({ "ZERO","Air", "Earth", "Fire", "Water" }) // Inicialitzem el vector amb els elements b�sics.
{
	printInterficie();
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
	"Your current score:" << score << std::endl <<
	"Your have these elements:" << std::endl <<
	"1:" << dispElements[1] << std::endl <<
	"2:" << dispElements[2] << std::endl <<
	"3:" << dispElements[3] << std::endl <<
	"4:" << dispElements[4] << std::endl;
}