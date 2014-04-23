#ifndef _POSITIONH
#define _POSITIONH
#include "Pattern.h"

/*
Une position représente un bloc : une séquence du morceau. Un pattern est affecté à un bloc. Ce même pattern peut être affecté à plusieurs blocs.
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