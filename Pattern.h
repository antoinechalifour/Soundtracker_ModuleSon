#ifndef _PATTERNH
#define _PATTERNH
#include <string>
#include "Piste.h"

/*
Classe repr�sentant un Sample.
Un sample est caract�ris� par :
- id : son identifiant au sein du morceau
- nom : son nom
- pistes : un tableau de 8 pistes.
*/
class Pattern{
private:
	static int nbPattern;
	int id;
	std::string nom;
	Piste pistes[8];

public:
	/* CONSTRUCTEURS */
	Pattern();
	Pattern(const Pattern&);

	/* GETTERS ET SETTERS */
	//Pas de setId() -> generation automatique
	inline int getID(){ return id; };

	std::string getNom();
	void setNom(std::string nom);

	/* DEBUG */
	void debug();
};

#endif