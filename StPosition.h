#ifndef _POSITIONH
#define _POSITIONH

#include "StPattern.h"

/**
 * @brief Une position repr�sente un bloc : une s�quence du morceau. Un pattern est affect� � un bloc.
 * Ce m�me pattern peut �tre affect� � plusieurs blocs.
 * @author Antoine
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
    StPosition(const StPosition& copie);

    void setPattern(StPattern* pattern);
    inline void setId(int id){ this->id = id; }

    static inline int getNbPositions(){ return nbPositions; }
    inline int getId() const { return id; }
    inline StPattern* getPattern() const { return pattern; }

	void debug();
};

#endif
