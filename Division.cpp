#include <iostream>
#include "Division.h"
#include "Sample.h"

using namespace std;

/*
Compteur des divisions, permettant l'attribution des identifiants à la construction.
*/
int Division::nbDivisions = 0;

/*
Constructeur par defaut. Initialise :
- l'identifiant en utilisant le nb de division
- la note à LA (440hZ)
- le volume au maximum, 100
*/
Division::Division() :
	id(nbDivisions),
	note(440),
	volume(100)
{
	nbDivisions++;
	sample = NULL;
}

/* 
Getters et Setters
*/
void Division::setSample(Sample* sample){
	this->sample = new Sample(*sample);
}

/* OPERATEURS*/
/*
Opérateur d'affectation
*/
Division& Division::operator=(const Division& d){
	this->id = d.id;
	this->note = d.note;
	this->volume = d.volume;
	this->sample = d.sample;

	return *this;
}

/* AUTRES METHODES */
void Division::play(){
	if (sample != NULL) sample->play(note, volume);
}

/* Méthode de débug
Affiche les informations connues sur la division.*/
void Division::debug(){
	cout << "Division " << id << endl;
	cout << "\t - Note : " << note << endl;
	cout << "\t - Volume : " << volume << endl;
	sample->debug();
}