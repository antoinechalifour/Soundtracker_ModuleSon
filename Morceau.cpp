#include "Morceau.h"
#include "StValueException.h"

/*
Constructeur par d�faut. Initialise :
- le tempo � 96
- le volume � son maximum, 100
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


/* Autres m�thodes */
/*
M�thode lan�ant la lecture. L'unit� de temps est la double croche (1 temps / 4 divisions).
*/
void Morceau::lecture(bool lect, int position, int division){
	if (lect){
		if (position < 0 || position > indexLastPosition) throw StValueException("La position demand�e n'existe pas");
		if (division < 0 || division > 63) throw StValueException("Le num�ro de division fourni n'est pas valide. Veuillez saisir un entier entre 1 et 64");
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
affecter un pattern � la position donn�e en index.
*/
void Morceau::affecterPattern(int position, Pattern* pattern){
	if (position > indexLastPosition + 1 || position < 0) throw StValueException("La position n'est pas valide.");
	if (position > indexLastPosition) indexLastPosition = position;
	positions[position].setPattern(pattern);
}

/*
Retourne une r�f�rence vers la division demand�e.
*/
Division& Morceau::getDivision(Pattern* pattern, int noPiste, int noDivision){
	if (noPiste< 0 || noPiste > 7) throw StValueException("Le num�ro de piste fourni n'est pas valide. Veuillez saisir un entier entre 1 et 8");
	if (noDivision < 0 || noDivision > 63) throw StValueException("Le num�ro de division fourni n'est pas valide. Veuillez saisir un entier entre 1 et 64");

	return pattern->getPiste(noPiste).getDivision(noDivision);
}

/* M�thode de d�bug
Affiche les informations connues sur le Morceau.*/
void Morceau::debug(){

}