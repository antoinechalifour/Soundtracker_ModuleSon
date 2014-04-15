#include <iostream>
#include "Pattern.h"

using namespace std;

/*
Compteur des patterns, permettant l'attribution des identifiants à la construction.
*/
int Pattern::nbPattern = 0;

/* CONSTRUCTEURS*/
/*
Constructeur par défaut. Initialise :
- l'id au nombre de pattern
- le nom à une valeur par défaut.
*/
Pattern::Pattern():
	id(nbPattern)
{
	setNom("Valeur par défaut");
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

/* Méthode de débug
Affiche les informations connues sur le Pattern.*/
void Pattern::debug(){
	cout << "Pattern : " << id << endl;
	cout << "\t - nom : " << nom << endl;/*
	for (int i = 0; i < 8; i++){
		pistes[i].debug();
		cout << "----------------------------" << endl;
	}*/
}