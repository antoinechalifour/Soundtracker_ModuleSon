#include "StDebug.h"
#include "StPiste.h"
#include "StValueException.h"

/*******************************************************************
 * VARIABLES
 * ****************************************************************/

/**
Compteur des pistes, permettant l'attribution des identifiants à la construction.
*/
int StPiste::nbPistes = 0;


/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/
StPiste::StPiste():
    id(nbPistes),
    mute(false),
    solo(false)
{
	nbPistes++;
}

StPiste::StPiste(const StPiste &copie):
    id(copie.id),
    mute(copie.mute),
    solo(copie.solo){}

/*******************************************************************
 * OPERATEURS
 * ****************************************************************/
StPiste& StPiste::operator=(const StPiste& p){
	this->mute = p.mute;
	this->solo = p.solo;
	this->id = p.id;
	for (int i = 0; i < 64; i++){
		this->divisions[i] = p.divisions[i];
	}

	return *this;
}


/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
StDivision& StPiste::getDivision(int index){
	if (index < 0 || index > 63) throw StValueException("La division n'est pas valide. Veuillez saisir un entier entre 0 et 63");
	return divisions[index];
}


/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StPiste::debug(){
	for (int i = 0; i < 63; i++){
		divisions[i].debug();
	}
}
