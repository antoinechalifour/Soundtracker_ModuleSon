#ifndef _POSITIONH
#define _POSITIONH

#include "StPattern.h"

/**
Une position représente un bloc : une séquence du morceau. Un pattern est affecté à un bloc.
Ce même pattern peut être affecté à plusieurs blocs.
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
