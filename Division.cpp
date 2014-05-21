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

bool Division::isRepeat(){
	if (this->sample != NULL){
		return sample->isRepeat();
	}
	else return false;
}

/* AUTRES METHODES */
void Division::play(bool p){
	if (p && sample != NULL){
		sample->play(note, volume);
	}
	else if (!p && sample != NULL){
		sample->stop();
	}
}

/* Méthode de débug
Affiche les informations connues sur la division.*/
void Division::debug(){
	cout << "Division " << id << endl;
	cout << "\t - Note : " << note << endl;
	cout << "\t - Volume : " << volume << endl;
	sample->debug();
}