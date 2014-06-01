#include "StMorceau.h"
#include "StValueException.h"

/*******************************************************************
 * CONSTRUCTEURS
 * ****************************************************************/

/**
Constructeur par défaut. Initialise :
- le tempo à 96
- le volume à son maximum, 100
*/
StMorceau::StMorceau():
	tempo(96),
	volume(100),
	indexLastPosition(-1)
{
    setNom("Morceau...");
}

StMorceau::StMorceau(const StMorceau &copie):
    tempo(copie.tempo),
    volume(copie.volume),
    indexLastPosition(copie.indexLastPosition),
    nom(copie.nom){}


/*******************************************************************
 * GETTERS / SETTERS
 * ****************************************************************/
void StMorceau::setNom(QString nom){
	this->nom = nom;
}

void StMorceau::affecterPattern(int position, StPattern* pattern){
    if (position > indexLastPosition + 1 || position < 0) throw StValueException("La position n'est pas valide.");
    if (position > indexLastPosition) {
        indexLastPosition = position;
        slot_indexLastPositionChanged();
    }
    positions[position].setPattern(pattern);
}

StDivision& StMorceau::getDivision(StPattern* pattern, int noPiste, int noDivision){
    if (noPiste< 0 || noPiste > 7) throw StValueException("Le numéro de piste fourni n'est pas valide. Veuillez saisir un entier entre 1 et 8");
    if (noDivision < 0 || noDivision > 63) throw StValueException("Le numéro de division fourni n'est pas valide. Veuillez saisir un entier entre 1 et 64");

    return pattern->getPiste(noPiste).getDivision(noDivision);
}


/*******************************************************************
 * METHODE LECTURE
 * ****************************************************************/
void StMorceau::lecture(bool lect, int position, int division){
    if(lect){
#ifdef STDEBUG
        cout<<"Lecture en cours, position= "<<position<<endl;
#endif
        currentPosition = position;
        currentDivision = division;
        currentCompteur = 64 - division;
        timer = new QTimer(0);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slot_play()));
        timer->start(60000/(tempo * 4));
    }
    else{
#ifdef STDEBUG
        cout<<"Lecture stopée"<<endl;
#endif
        timer->stop();
    }
}

void StMorceau::slot_play(){
#ifdef STDEBUG
    cout<<"Fonction play... Position= "<<currentPosition<<" - Division= "<<currentDivision<<endl;
#endif
    if(positions[currentPosition].getPattern() != NULL){
        positions[currentPosition].getPattern()->getPiste(0).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(1).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(2).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(3).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(4).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(5).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(6).getDivision(currentDivision).play(true);
        positions[currentPosition].getPattern()->getPiste(7).getDivision(currentDivision).play(true);
        currentDivision = (currentDivision+1) % 64;
        currentCompteur++;
        if(currentCompteur % 64 == 0) currentPosition ++;
    }
    else {
        cout<<"Fin de lecture"<<endl;
        timer->stop();
        cout<<"Timer stoppé"<<endl;
    }
}


/*******************************************************************
 * DEBUG
 * ****************************************************************/
void StMorceau::debug(){

}
