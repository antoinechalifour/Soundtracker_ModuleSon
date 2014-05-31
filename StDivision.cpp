#include "StDivision.h"


/*******************************************************************
 * VARIABLES
 * ****************************************************************/
/**
Compteur des divisions, permettant l'attribution des identifiants à la construction.
*/
int StDivision::nbDivisions = 0;


/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/
/**
Constructeur par defaut. Initialise :
- l'identifiant en utilisant le nb de division
- la note à LA (440hZ)
- le volume au maximum, 100
*/
StDivision::StDivision() :
	id(nbDivisions),
	note(440),
    volume(10)
{
	nbDivisions++;
	sample = NULL;
}

/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
void StDivision::setSample(StSample* sample){
    this->sample = new StSample(*sample);
}

bool StDivision::isRepeat(){
    if (this->sample != NULL){
        return sample->isRepeat();
    }
    else return false;
}

/*******************************************************************
 * OPERATEURS
 * ****************************************************************/
/**
Opérateur d'affectation
*/
StDivision& StDivision::operator=(const StDivision& d){
	this->id = d.id;
	this->note = d.note;
	this->volume = d.volume;
	this->sample = d.sample;

	return *this;
}

QString StDivision::getNoteAsQString(){
    int notes[12] = { FREQ_A,
                      FREQ_AS,
                      FREQ_B,
                      FREQ_C,
                      FREQ_CS,
                      FREQ_D,
                      FREQ_DS,
                      FREQ_E,
                      FREQ_F,
                      FREQ_FS,
                      FREQ_G,
                      FREQ_GS
                    };
    for(int i=0 ; i<12 ; i++){
        int freq = notes[i];
        if(note % freq == 0){
            QString noteAsString;
            int octave = (note / freq) - 1;
            switch(freq){
            case FREQ_A:
                noteAsString = "A";
                break;
            case FREQ_AS:
                noteAsString = "A#";
                break;
            default:
                noteAsString = "N";
                break;
            }
            noteAsString.append(octave);
            return noteAsString;
        }
    }
}

/*******************************************************************
 * METHODES LECTURE
 * ****************************************************************/
void StDivision::play(bool p){
	if (p && sample != NULL){
		sample->play(note, volume);
	}
	else if (!p && sample != NULL){
		sample->stop();
	}
}


/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StDivision::debug(){
	sample->debug();
}
