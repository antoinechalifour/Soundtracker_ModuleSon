#ifndef _POSITIONH
#define _POSITIONH
#include "Pattern.h"

/*
Une position repr�sente un bloc : une s�quence du morceau. Un pattern est affect� � un bloc. Ce m�me pattern peut �tre affect� � plusieurs blocs.
*/
class Position{
private:
	static int nbPositions;
	int id;
	Pattern* pattern;

public:
	/* CONSTRUCTEURS */
	Position();
		
	/* GETTERS ET SETTERS */
	//Pas de setId() -> generation automatique
	inline int getId(){ return id; };

	inline Pattern* getPattern(){ return pattern; };
	void setPattern(Pattern* pattern);

	/* METHODES STATIC */
	static inline int getNbPositions(){ return nbPositions; };

	/* DEBUG */
	void debug();
};

#endif