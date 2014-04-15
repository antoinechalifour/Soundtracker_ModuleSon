#include <iostream>
#include "Sample.h"

using namespace std;

/* VARIABLES STATIC*/
int Sample::nbSamples = 0;

/* CONSTRUCTEURS*/
/*
Constructeur par d�faut. Initialise :
- l'id � nbSample
- le volume � 100 (maximum)
- le repeat � false
- le repeatlen � -1
*/
Sample::Sample():
	id(nbSamples),
	volume(100),
	repeat(false),
	repeatlen(-1)
{
	nbSamples++;
	setNom("Entrez un nom...");
	sound = new ofSoundPlayer();
}

/*
Constructeur par recopie
*/
Sample::Sample(const Sample& s):
	id(s.id),
	volume(s.volume),
	repeat(s.repeat),
	repeatlen(s.repeatlen),
	sound(s.sound)
{
	setNom("Nom par defaut");
}

/* GETTERS ET SETTERS */
std::string Sample::getNom(){
	return nom;
}

void Sample::setNom(std::string nom){
	this->nom = nom;
}

void Sample::setSound(std::string name){
	sound->loadSound(name);
}

void Sample::setRepeat(bool repeat){
	this->repeat = repeat;
	sound->setLoop(repeat);
}

/* AUTRES METHODES */
void Sample::play(){
	sound->play();
}

void Sample::play(int note, int volume){
	float sp = ((float)note) / 440.0;
	float vol = ((float)volume) / 100.0;
	sound->setSpeed(sp);
	sound->setVolume(vol);
	sound->play();
}

/* M�thode de d�bug
Affiche les informations connues sur le Sample.*/
void Sample::debug(){
	if (this == NULL){
		cout << "Sample NULL" << endl;
		return;
	}
	cout << "Sample : " << id << endl;
	cout << "\t - Volume : " << volume << endl;
	cout << "\t - isRepeat : " << repeat << endl;
	cout << "\t - repeatlen : " << repeatlen << endl;
}