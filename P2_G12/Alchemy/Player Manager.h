#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Element_List.h"

class Player
{
private:

	// Variable que guarda l'índex del primer element del vector del jugador
	const int FIRST_ELEMENT=1;

	// Variable que guarda la puntuació del jugador.
	int score;

	// Variable de la classe Elements.
	Elements myElements;

	// Vector que guardarà els elements ja descoberts pel jugador.
	std::vector<std::string> discoveredElements;

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
	bool isNumber(std::string);

	//Funció que s'encarrega d'afegir els elements 4 elements bàsics segons l'input que introdueixi el jugador (string).
	void addBasics();

	//Funció que s'encarrega d'afegir l'element que el jugador seleccioni a través d'un int.
	void addElement(int numberElement);

	// Funció que s'encarrega d'afegir a la llista l'element creat amb la combinació dels altres dos i
	// després procedeix a eliminar-los.
	void combination(int n1, int n2);

	// Funció que mostra la puntuació per consola.
	void printScore();

	// Funció que mostra la llista d'elements per pantalla.
	void printElements();

	// Funció que ordena la llista d'elements alfabeticament.
	void sortElements();

	// Funció que elimina els elements repetits de la llista.
	void cleanElements();
};