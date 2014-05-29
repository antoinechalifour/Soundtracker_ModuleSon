#include "StDebug.h"
#include "StSample.h"

/*******************************************************************
 * VARIABLES
 * ****************************************************************/
int StSample::nbSamples = 0;

/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/
/**
Constructeur par défaut. Initialise :
- l'id à nbSample
- le volume à 100 (maximum)
- le repeat à false
- le repeatlen à -1
*/
StSample::StSample():
	id(nbSamples),
	volume(100),
	repeat(false),
	repeatlen(-1)
{
	nbSamples++;
	setNom("Entrez un nom...");
    sound = new QMediaPlayer;
}

/**
Constructeur par recopie
*/
StSample::StSample(const StSample& s):
	id(s.id),
	volume(s.volume),
	repeat(s.repeat),
	repeatlen(s.repeatlen),
	sound(s.sound)
{
	setNom("Nom par defaut");
}

/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
QString StSample::getNom(){
	return nom;
}

void StSample::setNom(QString nom){
	this->nom = nom;
}

void StSample::setSound(QString name){
    cout<<"Initialisation du son"<<endl;
    cout<<"Création de l'url"<<endl;
    sound->setMedia(QUrl::fromLocalFile(name));
}

void StSample::setRepeat(bool repeat){
    this->repeat = repeat;
}

/*******************************************************************
 * METHODES LECTURE
 * ****************************************************************/
void StSample::play(){
    cout<<"Lecture du sample... (0)"<<endl;
    sound->stop();
	sound->play();
}

void StSample::play(int note, int volume){
	float sp = ((float)note) / 440.0;
    sound->setPlaybackRate(sp);
    sound->setVolume(volume);
    this->play();
}

void StSample::stop(){
	sound->stop();
}

/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StSample::debug(){
    if (this == NULL){
		return;
    }
}
