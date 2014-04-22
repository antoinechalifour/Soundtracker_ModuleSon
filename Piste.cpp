#include <iostream>
#include "Piste.h"
#include "StValueException.h"

using namespace std;

/*
Compteur des pistes, permettant l'attribution des identifiants à la construction.
*/
int Piste::nbPistes = 0;

/* CONSTRUCTEURS */
/*
Constructeur par défaut. Initialise :
- solo à faux
- mute à faux
*/
Piste::Piste():
	solo(false),
	mute(false),
	id(nbPistes)
{
	nbPistes++;
}

/* OPERATEURS */
/*
Opérateur d'affectation
*/
Piste& Piste::operator=(const Piste& p){
	this->mute = p.mute;
	this->solo = p.solo;
	this->id = p.id;
	for (int i = 0; i < 64; i++){
		this->divisions[i] = p.divisions[i];
	}

	return *this;
}

/* AUTRES METHODES */
/* 
Retourne une référence vers la division demandée. Permet l'affectation et le paramétrage de la division.
*/
Division& Piste::getDivision(int index){
	if (index < 0 || index > 63) throw StValueException("La division n'est pas valide. Veuillez saisir un entier entre 0 et 63");
	return divisions[index];
}

/* Méthode de débug
Affiche les informations connues sur la piste.*/
void Piste::debug(){
	cout << "Piste : " << endl;
	cout << "\t - isMute : " << mute << endl;
	cout << "\t - isSolo : " << solo << endl;
	for (int i = 0; i < 63; i++){
		divisions[i].debug();
	}
}