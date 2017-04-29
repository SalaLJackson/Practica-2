#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Element_List.h"

class Player
{
private:

	// Variable que guarda l'�ndex del primer element del vector del jugador
	const int FIRST_ELEMENT=1;

	// Variable que guarda la puntuaci� del jugador.
	int score;

	// Variable de la classe Elements.
	Elements myElements;

	// Vector que guardar� els elements ja descoberts pel jugador.
	std::vector<std::string> discoveredElements;

public:

	// Constructor de la classe player.
	Player(Elements &Elements);

	// Vector que guardar� els elements disponibles pel jugador.
	std::vector<std::string> dispElements;

	// Funci� que retorna la puntuaci� del jugador.
	int getScore();

	// Funci� que imprimeix l'interf�cie base.
	void printInterficie();

	// Funci� que s'encarrega de comprovar si l'input del jugador �s un n�mero o b� �s una paraula.
	bool isNumber(std::string);

	//Funci� que s'encarrega d'afegir els elements 4 elements b�sics segons l'input que introdueixi el jugador (string).
	void addBasics();

	//Funci� que s'encarrega d'afegir l'element que el jugador seleccioni a trav�s d'un int.
	void addElement(int numberElement);

	// Funci� que s'encarrega d'afegir a la llista l'element creat amb la combinaci� dels altres dos i
	// despr�s procedeix a eliminar-los.
	void combination(int n1, int n2);

	// Funci� que mostra la puntuaci� per consola.
	void printScore();

	// Funci� que mostra la llista d'elements per pantalla.
	void printElements();

	// Funci� que ordena la llista d'elements alfabeticament.
	void sortElements();

	// Funci� que elimina els elements repetits de la llista.
	void cleanElements();
};