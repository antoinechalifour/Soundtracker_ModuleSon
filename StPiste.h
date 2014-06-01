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
    StPiste(const StPiste& copie);
    StPiste& operator=(const StPiste&);

    inline void setMute(bool mute){ this->mute = mute; }
    inline void setSolo(bool solo){ this->solo = solo; }

    static inline int getNbPistes(){ return nbPistes; }
    inline int getId(){ return id; }
    inline bool isMute(){ return mute; }
    inline bool isSolo(){ return solo; }
    StDivision& getDivision(int index);

    inline int getId() const { return id; }
    inline bool isMute() const { return mute; }
    inline bool isSolo() const { return solo; }
    inline StDivision& getDivision(int index) const {
        StDivision tmp(divisions[index]);
        return tmp;
    }


	void debug();
};

#endif
