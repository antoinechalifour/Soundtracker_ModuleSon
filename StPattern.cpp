#include "StDebug.h"
#include "StPattern.h"
#include "StValueException.h"

/*******************************************************************
 * VARIABLES
 * ****************************************************************/

/**
Compteur des patterns, permettant l'attribution des identifiants � la construction.
*/
int StPattern::nbPattern = 0;


/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/

/**
Constructeur par d�faut. Initialise :
- l'id au nombre de pattern
- le nom � une valeur par d�faut.
*/
StPattern::StPattern():
	id(nbPattern)
{
	setNom("Valeur par d�faut");
	nbPattern++;
}

/**
Constructeur par recopie.
*/
StPattern::StPattern(const StPattern& p):
	id(p.id)
{
	setNom(p.nom);
	for (int i = 0; i < 8; i++){
		pistes[i] = p.pistes[i];
	}
}

/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
QString StPattern::getNom(){
	return nom;
}

void StPattern::setNom(QString nom){
	this->nom = nom;
}


StPiste& StPattern::getPiste(int index){
	if (index < 0 || index > 7) throw StValueException("La piste fournie n'existe pas. Veuillez saisir un entier entre 1 et 8.");
	return pistes[index];
}


/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StPattern::debug(){/*
	for (int i = 0; i < 8; i++){
		pistes[i].debug();
		cout << "----------------------------" << endl;
	}*/
}
