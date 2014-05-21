#include "Morceau.h"
#include "StValueException.h"

/**
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

		/* GESTION DU REPEAT */
		bool repeat[8];
		int lastDiv[8];
		for (int i = 0; i < 8; i++){
			repeat[i] = positions[position].getPattern()->getPiste(i).getDivision(0).isRepeat();
			lastDiv[i] = 0;
		}

		/* BOUCLE DE LECTURE */
		/* POSITION */
		for (int i = position; i <= indexLastPosition; i++){
			/* DIVISION */
			for (int j = division; j < 64; j++){
				/* PISTE */
				for (int k = 0; k < 8; k++){
					/* ANNULER LE DERNIER REPEAT */
					if (repeat[i] && positions[i].getPattern()->getPiste(k).getDivision(j).getSample() != NULL){
						cout << "Arret de la division " << j << " de la piste " << k <<endl;
						positions[i].getPattern()->getPiste(k).getDivision(lastDiv[k]).play(false);
					}

					/* INITIALISER LE NOUVEAU REPEAT*/
					if (positions[i].getPattern()->getPiste(k).getDivision(j).isRepeat()){
						cout << "Un nouveau repeat a été detecte division " << j << " de la piste " << k <<endl;
						repeat[k] = true;
						lastDiv[k] = j;
					}

					/* LANCER LA LECTURE */
					positions[i].getPattern()->getPiste(k).getDivision(j).play(true);
				}

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