#include "StDebug.h"
#include "StSample.h"

/*******************************************************************
 * VARIABLES
 * ****************************************************************/
int StSample::nbSamples = 0;

/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/
StSample::StSample():
	id(nbSamples),
	volume(100),
	repeat(false),
    repeatlen(-1),
    pitch(440)
{
#ifdef STDEBUG
    cout<<"Creation du sample id= "<<id<<endl;
#endif
	nbSamples++;
	setNom("Entrez un nom...");
    sound = new QMediaPlayer;
}

StSample::StSample(const StSample& s):
	id(s.id),
	volume(s.volume),
	repeat(s.repeat),
	repeatlen(s.repeatlen),
    pitch(s.pitch),
	sound(s.sound)
{
	setNom("Nom par defaut");
}

/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
void StSample::setNom(QString nom){
	this->nom = nom;
}

void StSample::setSound(QString name){
    cout<<"Initialisation du son"<<endl;
    cout<<"Cr�ation de l'url"<<endl;
    this->setNom(name);
    sound->setMedia(QUrl::fromLocalFile(name));
    //sound->setSource(QUrl::fromLocalFile(name));
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

void StSample::play(int note, int divVolume){
	float sp = ((float)note) / 440.0;
    sound->setPlaybackRate(sp);
    float vol = (divVolume / 10) * volume;
    sound->setVolume((int) vol);
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
