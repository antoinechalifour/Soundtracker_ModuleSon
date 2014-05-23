#ifndef _MORCEAUH
#define _MORCEAUH

#include "StDebug.h"
#include "StPosition.h"
#include "StDivision.h"
#include "StPattern.h"

/**
Classe représentant le morceau.
Un morceau est caractérisé par :
- nom : son nom
- tempo : son tempo (supérieur à 0)
- volume son volume (compris entre 1 et 100)
*/

class StMorceau : public QObject{
private:
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
    QString nom;
	int tempo;
	int volume;
    StPosition positions[128];
	int indexLastPosition;

    //Gestion de la lecture dans le timer
    QTimer* timer;
    int currentPosition;
    int currentDivision;
    int currentCompteur;

    Q_OBJECT
public:
    /*******************************************************************
     * METHODES
     * ****************************************************************/
    StMorceau();

    QString getNom();
    void setNom(QString);
    inline int getTempo(){ return tempo; }
    inline void setTempo(int tempo){ this->tempo = tempo; }
    inline int getVolume(){ return volume; }
    inline void setVolume(int volume){ this->volume = volume; }
    StDivision& getDivision(StPattern*, int, int);

	void lecture(bool, int, int);
    void affecterPattern(int position, StPattern* pattern);

	void debug();

signals:
public slots:
    void slot_play();
};
#endif
