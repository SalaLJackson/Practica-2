#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

// Classe que s'ocuparà d'emmagatzemar i controlar el llistat d'elements i combinacions.

class Elements
{
	private:
		const int NUM_COMBINATIONS=390;
		// Creem un struct i sobrecarguem els operadors per a aixó poder utilizar dos strings com a key.
		struct elements
		{
			std::string k1;
			std::string k2;

			// DEFINIM L'OPERACIÓ DE COMPARACIÓ PER IGUALTAT
			bool operator==(const elements &other) const
			{
				return(k1 == other.k1 && k2 == other.k2);
			};

			// DEFINIM L'OPERADOR ()
			size_t operator()(const elements &other) const
			{
				return((std::hash<std::string>()(other.k1) ^ (std::hash<std::string>()(other.k2)<<1)>>1));
			}
		};
		// En aquest Unordered Map hi guardarem els elements i les combinacions. La idea es fer que les combinacions serveixin com a keys per als diferents elements,
		// de manera que cada element del unordered map necessitarà de dos keys diferents per a accedir a aquests. Vam prendre aquesta decisió després de veure
		// que en alguns casos, dos combinacions diferents podien crear el mateix element, de manera que si utilitzessim com a key els elements, això podria donar errors.
		std::unordered_map<elements,std::string,elements> elementMap;
	public:
		Elements(); // Constructor de la nostra classe.
};