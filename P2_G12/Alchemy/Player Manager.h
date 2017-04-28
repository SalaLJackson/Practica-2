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

	// Vector que guardarà els elements disponibles pel jugador.
	std::vector<std::string> dispElements;

	// Variable de la classe Elements.
	Elements myElements;

	// Funció que imprimeix l'interfície base.
	void printInterficie();

public:

	// Constructor de la classe player.
	Player(Elements Elements);

	// Funció que retorna la puntuació del jugador.
	int getScore();
};