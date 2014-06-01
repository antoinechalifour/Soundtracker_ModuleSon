#ifndef _POSITIONH
#define _POSITIONH

#include "StPattern.h"

/**
Une position repr�sente un bloc : une s�quence du morceau. Un pattern est affect� � un bloc.
Ce m�me pattern peut �tre affect� � plusieurs blocs.
 *@author Antoine
*/

class StPosition{
private:
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
	static int nbPositions;
	int id;
    StPattern* pattern;

public:
    /*******************************************************************
     * METHODES
     * ****************************************************************/
    StPosition();

    static inline int getNbPositions(){ return nbPositions; }
    inline int getId(){ return id; }
    inline StPattern* getPattern(){ return pattern; }
    void setPattern(StPattern* pattern);

	void debug();
};

#endif
