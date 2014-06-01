#ifndef _DIVISIONH
#define _DIVISIONH

#include "StSample.h"

/**
Classe représentant une division.
Une division correspond à une unité de temps. Elle est caractérisée par :
    - une note (fréquence)
    - un sample
    - un volume (pour la division)

 *@author Antoine
*/
class StDivision{
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
private:
	static int nbDivisions;
	int id;
	int note;
	int volume;
    StSample* sample;

    /*******************************************************************
     * METHODES
     * ****************************************************************/
public:
    /**
    Constructeur par defaut. Initialise :
        - l'identifiant en utilisant le nb de division
        - la note à LA (440hZ)
        - le volume au maximum, 100
    */
    StDivision();
    /**
      Opérateur d'affectation. Recopie les valeurs.
     * @brief operator =
     * @return la référence vers la nouvelle division.
     */
    StDivision& operator=(const StDivision&);

    static inline int getNbDivisions(){ return nbDivisions; }
    inline int getId(){ return id; }
    inline void setId(int id){ this->id = id; }
    inline int getNote(){ return note; }
    inline void setNote(int note){ this->note = note; }
    inline int getVolume(){ return volume; }
    inline void setVolume(int volume){ this->volume = volume; }
    inline StSample* getSample(){ return sample; }
    void setSample(StSample* sample);
	bool isRepeat();

    /**
      Retourne la note sous forme de QString
      Exemple : 440 -> A2
     * @brief getNoteAsQString
     * @return le note sous forme de QString
     */
    QString getNoteAsQString();

    /**
      Commence la lecture de la division.
     * @brief play
     */
	void play(bool);

	void debug();
};

#endif
