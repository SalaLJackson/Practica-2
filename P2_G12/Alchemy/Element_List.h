#pragma once
#include <unordered_map>
#include <string>

// Classe que s'ocupar� d'emmagatzemar i controlar el llistat d'elements i combinacions.

class Elements
{
	private:
		// En aquest Unordered Map hi guardarem els elements i les combinacions. La idea es fer que les combinacions serveixin com a keys per als diferents elements,
		// de manera que cada element del unordered map necessitar� de dos keys diferents per a accedir a aquests. Vam prendre aquesta decisi� despr�s de veure
		// que en alguns casos, dos combinacions diferents podien crear el mateix element, de manera que si utilitzessim com a key els elements, aix� podria donar errors.
		//std::unordered_map<std::pair<std::string,std::string>, std::string> elementMap;
	public:
		Elements(); // Constructor de la nostra classe.
};