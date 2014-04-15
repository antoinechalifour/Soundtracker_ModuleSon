#include "Morceau.h"

/*
Constructeur par d�faut. Initialise :
- le tempo � 96
- le volume � son maximum, 100
*/
Morceau::Morceau():
	tempo(96),
	volume(100)
{
	//setNom("Morceau...");
}

/* Getters et Setters*/
std::string Morceau::getNom(){
	return nom;
}

void Morceau::setNom(std::string nom){
	this->nom = nom;
}

/* Autres m�thodes */
void Morceau::lecture(bool lect, int pattern, int division){

}

/* M�thode de d�bug
Affiche les informations connues sur le Morceau.*/
void Morceau::debug(){

}