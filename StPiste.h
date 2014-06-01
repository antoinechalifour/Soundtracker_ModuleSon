#ifndef _PISTEH
#define _PISTEH

#include "StDivision.h"

/**
Classe représentant une Piste.
Une piste est caractérisée par :
- mute : booléen indiquant si la piste est à lire ou pas
- solo : indique si la piste est à lire en solo
- un tableau de 64 divisions à lire successivement.

 *@author Antoine
*/

class StPiste{
private:
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
	static int nbPistes;
	int id;
	bool mute;
	bool solo;
    StDivision divisions[64];

public:
    /*******************************************************************
     * METHODES
     * ****************************************************************/
    StPiste();

    inline int getId(){ return id; }
    static inline int getNbPistes(){ return nbPistes; }
    inline bool isMute(){ return mute; }
    inline void setMute(bool mute){ this->mute = mute; }
    inline bool isSolo(){ return solo; }
    inline void setSolo(bool solo){ this->solo = solo; }
    StDivision& getDivision(int index);

    StPiste& operator=(const StPiste&);

	void debug();
};

#endif
