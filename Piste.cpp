#include <iostream>
#include "Piste.h"

using namespace std;

/* CONSTRUCTEURS */
/*
Constructeur par d�faut. Initialise :
- solo � faux
- mute � faux
*/
Piste::Piste():
	solo(false),
	mute(false)
{}

/* OPERATEURS */
/*
Op�rateur d'affectation
*/
Piste& Piste::operator=(const Piste& p){
	this->mute = p.mute;
	this->solo = p.solo;
	for (int i = 0; i < 64; i++){
		this->divisions[i] = p.divisions[i];
	}

	return *this;
}

/* AUTRES METHODES */
/* 
Retourne une r�f�rence vers la division demand�e. Permet l'affectation et le param�trage de la division.
*/
Division& Piste::getDivision(int index){
	return divisions[index];
}

/*
Joue la piste de la premi�re � la derni�re division
*/
void Piste::play(int tempo){
	play(tempo, 0);
}

/*
Joue la piste � partir de la division donn�e en param�tre.
*/
void Piste::play(int tempo, int div){
	int ms = ((float)tempo) / 60.0 * 125;
	for (int i = div; i < 64; i++){
		divisions[i].play();
		Sleep(ms);
	}
}

/* M�thode de d�bug
Affiche les informations connues sur la piste.*/
void Piste::debug(){
	cout << "Piste : " << endl;
	cout << "\t - isMute : " << mute << endl;
	cout << "\t - isSolo : " << solo << endl;
	for (int i = 0; i < 63; i++){
		divisions[i].debug();
	}
}