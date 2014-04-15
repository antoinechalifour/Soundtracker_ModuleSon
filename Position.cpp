#include <iostream>
#include "Position.h"

using namespace std;

/*
Compteur des positions, permettant l'attribution des identifiants à la construction.
*/
int Position::nbPositions = 0;

/*
Constructeur par défaut. Initialise :
- l'id au nombre de position.
- le pattern à NULL pour éviter toute fuite de mémoire.
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

/* Méthode de débug
Affiche les informations connues sur la Position.*/
void Position::debug(){
	cout << "Position : " << id << endl;
	if (pattern == NULL){
		cout << "Pattern NULL" << endl;
		return;
	}
	pattern->debug();
}