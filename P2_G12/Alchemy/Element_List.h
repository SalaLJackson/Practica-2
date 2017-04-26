#pragma once
#include <unordered_map>

// Classe que s'ocuparà d'emmagatzemar i controlar el llistat d'elements i combinacions.

class Elements
{
	private:
		std::unordered_map<std::string, std::string> elementMap; // En aquest Unordered Map hi guardarem els elements i les combinacions. La idea es fer que els diferents elements siguin les keys que apunten a les combinacions per a crear-los.
	public:
		Elements(); // Constructor de la nostra classe.
};