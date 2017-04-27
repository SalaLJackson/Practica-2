#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include "Element_List.h"

void main()
{
	Elements llistat;
	int score = 0; //Puntuació del jugador

	//Creem el vector dels 4 elements inicials el qual s'anira actualitzan segons les combinacions correctes que escrigui el jugador

	std::vector<std::string> combinacions({ "ZERO","Air", "Earth", "Fire", "Water" }); //Vector inicial que anirà augmentat a mesura que el jugador endivini combos

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
	":"	<<	combinacions[1] << std::endl <<
	":"	<<	combinacions[2] << std::endl <<
	":" <<  combinacions[3] << std::endl <<
	":" <<  combinacions[4] << std::endl;





}