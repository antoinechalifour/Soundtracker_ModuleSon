#include <iostream>
#include "Pattern.h"
#include "StValueException.h"

using namespace std;

/*
Compteur des patterns, permettant l'attribution des identifiants � la construction.
*/
int Pattern::nbPattern = 0;

/* CONSTRUCTEURS*/
/*
Constructeur par d�faut. Initialise :
- l'id au nombre de pattern
- le nom � une valeur par d�faut.
*/
Pattern::Pattern():
	id(nbPattern)
{
	setNom("Valeur par d�faut");
	nbPattern++;
}

/*
Constructeur par recopie.
*/
Pattern::Pattern(const Pattern& p):
	id(p.id)
{
	setNom(p.nom);
	for (int i = 0; i < 8; i++){
		pistes[i] = p.pistes[i];
	}
}

/* Getters et Setters non inline.
Les getters / setters inlines sont dans Pattern.h
*/
std::string Pattern::getNom(){
	return nom;
}

void Pattern::setNom(std::string nom){
	this->nom = nom;
}


Piste& Pattern::getPiste(int index){
	if (index < 0 || index > 7) throw StValueException("La piste fournie n'existe pas. Veuillez saisir un entier entre 1 et 8.");
	return pistes[index];
}

/* M�thode de d�bug
Affiche les informations connues sur le Pattern.*/
void Pattern::debug(){
	cout << "Pattern : " << id << endl;
	cout << "\t - nom : " << nom << endl;/*
	for (int i = 0; i < 8; i++){
		pistes[i].debug();
		cout << "----------------------------" << endl;
	}*/
}