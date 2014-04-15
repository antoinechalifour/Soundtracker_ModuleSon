#pragma once
#include <string>

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

	/* DEBUG */
	void debug();
};