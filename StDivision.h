#ifndef _DIVISIONH
#define _DIVISIONH

#include "StSample.h"

/**
Classe repr�sentant une division.
Une division correspond � une unit� de temps. Elle est caract�ris�e par :
    - une note (fr�quence)
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
        - la note � LA (440hZ)
        - le volume au maximum, 100
    */
    StDivision();

    StDivision(const StDivision& copie);
    /**
      Op�rateur d'affectation. Recopie les valeurs.
     * @brief operator =
     * @return la r�f�rence vers la nouvelle division.
     */
    StDivision& operator=(const StDivision&);

    inline void setId(int id){ this->id = id; }
    inline void setNote(int note){ this->note = note; }
    inline void setVolume(int volume){ this->volume = volume; }
    void setSample(StSample* sample);

    static inline int getNbDivisions(){ return nbDivisions; }
    inline int getId() const { return id; }
    inline int getNote() const { return note; }
    inline int getVolume() const { return volume; }
    inline StSample* getSample(){ return sample; }
    inline StSample* getSample() const { return sample; }
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
