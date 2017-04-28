#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

// Classe que s'ocupar� d'emmagatzemar i controlar el llistat d'elements i combinacions.

class Elements
{
	private:

		// Nombre total de combinacions.
		const int NUM_COMBINATIONS = 390;

		// Nombre d'elements b�sics.
		const int NUM_BASICS = 4;

		// Creem un struct i sobrecarguem els operadors per a aix� poder utilizar dos strings com a key.
		struct elements
		{
			std::string k1;
			std::string k2;

			// DEFINIM L'OPERACI� DE COMPARACI� PER IGUALTAT
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
		// de manera que cada element del unordered map necessitar� de dos keys diferents per a accedir a aquests. Vam prendre aquesta decisi� despr�s de veure
		// que en alguns casos, dos combinacions diferents podien crear el mateix element, de manera que si utilitzessim com a key els elements, aix� podria donar errors.
		std::unordered_map<elements,std::string,elements> elementMap;

	public:

		// Constructor de la nostra classe.
		Elements();

		// Retorna el nombre de combinacions.
		int getNumComb();

		// Retorna el nombre d'elements b�sics.
		int getNumBasics();
};