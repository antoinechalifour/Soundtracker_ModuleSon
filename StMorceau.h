#ifndef _MORCEAUH
#define _MORCEAUH

#include "StDebug.h"
#include "StPosition.h"
#include "StDivision.h"
#include "StPattern.h"

/**
Classe repr�sentant le morceau.
Un morceau est caract�ris� par :
- nom : son nom
- tempo : son tempo (sup�rieur � 0)
- volume son volume (compris entre 1 et 100)

 *@author Antoine
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
    StMorceau(const StMorceau& copie);

    void setNom(QString);
    inline QString getNom() { return nom; }
    inline int getTempo() { return tempo; }
    inline void setTempo(int tempo){ this->tempo = tempo; }
    inline int getVolume() { return volume; }
    inline void setVolume(int volume){ this->volume = volume; }
    inline StPosition& getPosition(int i){ return positions[i]; }
    StDivision& getDivision(StPattern*, int, int);
    inline int getLastPosition(){ return indexLastPosition+1; }

    inline QString getNom() const { return nom; }
    inline int getTempo() const { return tempo; }
    inline int getVolume() const { return volume; }

    /**
      Lis le morceau (bool=true) � partir de la position et de la division donn�es.
      Stop la lecture (bool=false).
     * @brief lecture
     * @param lect lecture/stop
     * @param position la position de d�part
     * @param division la division de d�part
     */
    void lecture(bool lect, int position, int division);

    /**
      Affecte un pattern � une position donn�e.
     * @brief affecterPattern
     * @param position le num�ro de position
     * @param pattern un pointeur vers le pattern.
     */
    void affecterPattern(int position, StPattern* pattern);

	void debug();

signals:
    void slot_indexLastPositionChanged();

public slots:
    /**
      Lance la lecture (utilise QTimer).
     * @brief slot_play
     */
    void slot_play();
};
#endif
