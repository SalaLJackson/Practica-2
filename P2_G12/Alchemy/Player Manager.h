#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Element_List.h"

class Player
{
private:

	// Variable que guarda la puntuació del jugador.
	int score;

	// Variable de la classe Elements.
	Elements myElements;

public:

	// Constructor de la classe player.
	Player(Elements &Elements);

	// Vector que guardarà els elements disponibles pel jugador.
	std::vector<std::string> dispElements;

	// Funció que retorna la puntuació del jugador.
	int getScore();

	// Funció que imprimeix l'interfície base.
	void printInterficie();

	// Funció que s'encarrega de comprovar si l'input del jugador és un número o bé és una paraula.
	bool isWord(std::string);
};