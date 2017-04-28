#pragma once
#include <vector>
#include <string>

class Player
{
private:
	// Variable que guarda la puntuació del jugador.
	int score;
	// Vector que guardarà els elements disponibles pel jugador.
	std::vector<std::string> dispElements;
	// Funció que imprimeix l'interfície base
	void printInterficie();
public:
	// Constructor de la classe player.
	Player();
};