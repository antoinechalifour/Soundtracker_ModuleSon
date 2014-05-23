#ifndef _DIVISIONH
#define _DIVISIONH

#include "StSample.h"

/**
Classe représentant une division.
*/
class StDivision{
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
private:
	static int nbDivisions;
	int id;
	int note;
	int volume;
    StSample* sample;

    /*******************************************************************
     * METHODES
     * ****************************************************************/
public:
    StDivision();

    static inline int getNbDivisions(){ return nbDivisions; }
    inline int getId(){ return id; }
    inline void setId(int id){ this->id = id; }
    inline int getNote(){ return note; }
    inline void setNote(int note){ this->note = note; }
    inline int getVolume(){ return volume; }
    inline void setVolume(int volume){ this->volume = volume; }
    inline const StSample* getSample(){ return sample; }
    void setSample(StSample* sample);
	bool isRepeat();

    StDivision& operator=(const StDivision&);

	void play(bool);

	void debug();
};

#endif
