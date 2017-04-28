#pragma once
#include <vector>
#include <string>
#include "Element_List.h"

class Player
{
private:
	// Variable que guarda la puntuació del jugador.
	int score;
	// Vector que guardarà els elements disponibles pel jugador.
	std::vector<std::string> dispElements;
	// Funció que imprimeix l'interfície base.
	void printInterficie();
	// Variable de la classe Elements.
	Elements myElements;
public:
	// Constructor de la classe player.
	Player(Elements Elements);
};