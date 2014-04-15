#ifndef _DIVISIONH
#define _DIVISIONH
#include "Sample.h"

/*
Classe représentant une division.
*/
class Division{
	/* --------------- ATTRIBUTS --------------- */
private:
	static int nbDivisions;
	int id;
	int note;
	int volume;
	Sample* sample;

	/* --------------- METHODES --------------- */
public:
	/* CONSTRUCTEURS */
	Division();

	/* GETTERS ET SETTERS */
	inline int getId(){ return id; };
	inline void setId(int id){ this->id = id; };

	inline int getNote(){ return note; };
	inline void setNote(int note){ this->note = note; };

	inline int getVolume(){ return volume; };
	inline void setVolume(int volume){ this->volume = volume; };

	inline const Sample* getSample(){ return sample; };
	void setSample(Sample* sample);

	/* OPERATEURS */
	Division& operator=(const Division&);

	/* AUTRES METHODES */
	void play();

	/* DEBUG */
	void debug();
};

#endif