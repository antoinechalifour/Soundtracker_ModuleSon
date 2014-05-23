#include "StDebug.h"
#include "StPosition.h"


/*******************************************************************
 * VARIABLES
 * ****************************************************************/

/**
Compteur des positions, permettant l'attribution des identifiants � la construction.
*/
int StPosition::nbPositions = 0;

/**
Constructeur par d�faut. Initialise :
- l'id au nombre de position.
- le pattern � NULL pour �viter toute fuite de m�moire.
*/
StPosition::StPosition():
	id(nbPositions),
	pattern(NULL)
{
	nbPositions++;
}


/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
void StPosition::setPattern(StPattern* pattern){
	this->pattern = pattern;
}


/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StPosition::debug(){
    if (pattern == NULL){
		return;
	}
	pattern->debug();
}
