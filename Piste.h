#ifndef _PISTEH
#define _PISTEH
#include "Division.h"
/*
Classe représentant une Piste.
Une piste est caractérisée par :
- mute : booléen indiquant si la piste est à lire ou pas
- solo : indique si la piste est à lire en solo
- un tableau de 64 divisions à lire successivement.
*/
class Piste{
private:
	//int id;
	bool mute;
	bool solo;
	Division divisions[64];

public:
	/*CONSTRUCTEURS */
	Piste();

	/* GETTERS ET SETTERS */
	//inline int getId(){ return id; };
	//inline void setId(int id){ this->id = id; };

	inline bool isMute(){ return mute; };
	inline void setMute(bool mute){ this->mute = mute; };

	inline bool isSolo(){ return solo; };
	inline void setSolo(bool solo){ this->solo = solo; };

	/* OPERATEURS */
	Piste& operator=(const Piste&);

	/* AUTRES METHODES */
	Division& getDivision(int index);

	/* DEBUG */
	void debug();
};

#endif