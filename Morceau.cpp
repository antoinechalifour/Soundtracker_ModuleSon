#include "Morceau.h"
#include "StValueException.h"

/*
Constructeur par défaut. Initialise :
- le tempo à 96
- le volume à son maximum, 100
*/
Morceau::Morceau():
	tempo(96),
	volume(100),
	indexLastPosition(-1)
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
/*
Méthode lançant la lecture. L'unité de temps est la double croche (1 temps / 4 divisions).
*/
void Morceau::lecture(bool lect, int position, int division){
	if (lect){
		if (position < 0 || position > indexLastPosition) throw StValueException("La position demandée n'existe pas");
		if (division < 0 || division > 63) throw StValueException("Le numéro de division fourni n'est pas valide. Veuillez saisir un entier entre 1 et 64");
		for (int i = position; i <= indexLastPosition; i++){
			for (int j = division; j < 64; j++){
				positions[i].getPattern()->getPiste(0).getDivision(j).play();
				positions[i].getPattern()->getPiste(1).getDivision(j).play();
				positions[i].getPattern()->getPiste(2).getDivision(j).play();
				positions[i].getPattern()->getPiste(3).getDivision(j).play();
				positions[i].getPattern()->getPiste(4).getDivision(j).play();
				positions[i].getPattern()->getPiste(5).getDivision(j).play();
				positions[i].getPattern()->getPiste(6).getDivision(j).play();
				positions[i].getPattern()->getPiste(7).getDivision(j).play();

				Sleep(75);
			}
		}
	}
}

/*
affecter un pattern à la position donnée en index.
*/
void Morceau::affecterPattern(int position, Pattern* pattern){
	if (position > indexLastPosition + 1 || position < 0) throw StValueException("La position n'est pas valide.");
	if (position > indexLastPosition) indexLastPosition = position;
	positions[position].setPattern(pattern);
}

/*
Retourne une référence vers la division demandée.
*/
Division& Morceau::getDivision(Pattern* pattern, int noPiste, int noDivision){
	if (noPiste< 0 || noPiste > 7) throw StValueException("Le numéro de piste fourni n'est pas valide. Veuillez saisir un entier entre 1 et 8");
	if (noDivision < 0 || noDivision > 63) throw StValueException("Le numéro de division fourni n'est pas valide. Veuillez saisir un entier entre 1 et 64");

	return pattern->getPiste(noPiste).getDivision(noDivision);
}

/* Méthode de débug
Affiche les informations connues sur le Morceau.*/
void Morceau::debug(){

}