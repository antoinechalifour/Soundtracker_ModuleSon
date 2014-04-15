#pragma once
#include <string>

/*
Classe représentant le morceau.
Un morceau est caractérisé par :
- nom : son nom
- tempo : son tempo (supérieur à 0)
- volume son volume (compris entre 1 et 100)
*/
class Morceau{
private:
	/* --------------- ATTRIBUTS --------------- */
	std::string nom;
	int tempo;
	int volume;

public:
	/* --------------- Méthodes --------------- */
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

	/* DEBUG */
	void debug();
};