#include <iostream>
#include "Position.h"

using namespace std;

/*
Compteur des positions, permettant l'attribution des identifiants � la construction.
*/
int Position::nbPositions = 0;

/*
Constructeur par d�faut. Initialise :
- l'id au nombre de position.
- le pattern � NULL pour �viter toute fuite de m�moire.
*/
Position::Position():
	id(nbPositions),
	pattern(NULL)
{
	nbPositions++;
}

/* GETTERS ET SETTERS */
void Position::setPattern(Pattern* pattern){
	this->pattern = pattern;
}

/* M�thode de d�bug
Affiche les informations connues sur la Position.*/
void Position::debug(){
	cout << "Position : " << id << endl;
	if (pattern == NULL){
		cout << "Pattern NULL" << endl;
		return;
	}
	pattern->debug();
}