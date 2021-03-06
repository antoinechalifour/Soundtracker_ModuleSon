#include "StDebug.h"
#include "StPosition.h"


/*******************************************************************
 * VARIABLES
 * ****************************************************************/

/**
Compteur des positions, permettant l'attribution des identifiants � la construction.
*/
int StPosition::nbPositions = 0;

StPosition::StPosition():
	id(nbPositions),
	pattern(NULL)
{
	nbPositions++;
}

StPosition::StPosition(const StPosition &copie):
    id(copie.id),
    pattern(copie.pattern){}

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
