#include "Morceau.h"

/*
Constructeur par défaut. Initialise :
- le tempo à 96
- le volume à son maximum, 100
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

/* Autres méthodes */
void Morceau::lecture(bool lect, int pattern, int division){

}

/* Méthode de débug
Affiche les informations connues sur le Morceau.*/
void Morceau::debug(){

}