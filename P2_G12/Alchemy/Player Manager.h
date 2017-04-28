#pragma once
#include <vector>
#include <string>

class Player
{
private:
	// Variable que guarda la puntuaci� del jugador.
	int score;
	// Vector que guardar� els elements disponibles pel jugador.
	std::vector<std::string> dispElements;
	// Funci� que imprimeix l'interf�cie base
	void printInterficie();
public:
	// Constructor de la classe player.
	Player();
};