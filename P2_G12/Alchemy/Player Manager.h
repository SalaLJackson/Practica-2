#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Element_List.h"

class Player
{
private:

	// Variable que guarda la puntuaci� del jugador.
	int score;

	// Variable de la classe Elements.
	Elements myElements;

	// Funci� que imprimeix l'interf�cie base.
	void printInterficie();

public:

	// Constructor de la classe player.
	Player(Elements &Elements);

	// Vector que guardar� els elements disponibles pel jugador.
	std::vector<std::string> dispElements;

	// Funci� que retorna la puntuaci� del jugador.
	int getScore();
};