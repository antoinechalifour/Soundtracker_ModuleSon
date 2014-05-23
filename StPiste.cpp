#include "StDebug.h"
#include "StPiste.h"
#include "StValueException.h"

/*******************************************************************
 * VARIABLES
 * ****************************************************************/

/**
Compteur des pistes, permettant l'attribution des identifiants � la construction.
*/
int StPiste::nbPistes = 0;


/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/
/**
Constructeur par d�faut. Initialise :
- solo � faux
- mute � faux
*/
StPiste::StPiste():
    id(nbPistes),
    mute(false),
    solo(false)
{
	nbPistes++;
}


/*******************************************************************
 * OPERATEURS
 * ****************************************************************/
/**
Op�rateur d'affectation
*/
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
/**
Retourne une r�f�rence vers la division demand�e. Permet l'affectation et le param�trage de la division.
*/
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
