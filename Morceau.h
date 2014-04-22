#pragma once
#include <string>
#include "Position.h"
#include "Division.h"
#include "Pattern.h"

/*
Classe repr�sentant le morceau.
Un morceau est caract�ris� par :
- nom : son nom
- tempo : son tempo (sup�rieur � 0)
- volume son volume (compris entre 1 et 100)
*/
class Morceau{
private:
	/* --------------- ATTRIBUTS --------------- */
	std::string nom;
	int tempo;
	int volume;
	Position positions[128];
	int indexLastPosition;

public:
	/* --------------- M�thodes --------------- */
	/* CONSTRUCTEURS */
	Morceau();

	/* GETTERS ET SETTERS*/
	std::string getNom();
	void setNom(std::string);

	int getTempo();
	void setTempo(int);

	int getVolume();
	void setVolume(int);

	/* METHODES */
	void lecture(bool, int, int);
	void affecterPattern(int position, Pattern* pattern);
	Division& getDivision(Pattern*, int, int);

	/* DEBUG */
	void debug();
};