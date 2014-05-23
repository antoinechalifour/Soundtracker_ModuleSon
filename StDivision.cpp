#include "StDivision.h"


/*******************************************************************
 * VARIABLES
 * ****************************************************************/
/**
Compteur des divisions, permettant l'attribution des identifiants à la construction.
*/
int StDivision::nbDivisions = 0;


/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/
/**
Constructeur par defaut. Initialise :
- l'identifiant en utilisant le nb de division
- la note à LA (440hZ)
- le volume au maximum, 100
*/
StDivision::StDivision() :
	id(nbDivisions),
	note(440),
	volume(100)
{
	nbDivisions++;
	sample = NULL;
}

/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
void StDivision::setSample(StSample* sample){
    this->sample = new StSample(*sample);
}

bool StDivision::isRepeat(){
    if (this->sample != NULL){
        return sample->isRepeat();
    }
    else return false;
}

/*******************************************************************
 * OPERATEURS
 * ****************************************************************/
/**
Opérateur d'affectation
*/
StDivision& StDivision::operator=(const StDivision& d){
	this->id = d.id;
	this->note = d.note;
	this->volume = d.volume;
	this->sample = d.sample;

	return *this;
}


/*******************************************************************
 * METHODES LECTURE
 * ****************************************************************/
void StDivision::play(bool p){
	if (p && sample != NULL){
		sample->play(note, volume);
	}
	else if (!p && sample != NULL){
		sample->stop();
	}
}


/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StDivision::debug(){
	sample->debug();
}
