#ifndef _DIVISIONH
#define _DIVISIONH

#include "StSample.h"
/**
 * @brief The StDivision class - Classe repr�sentant une division.
 * Une division correspond � une unit� de temps. Elle est caract�ris�e par :
 *     - une note (fr�quence)
 *     - un sample
 *     - un volume (pour la division)
 * @author Antoine
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
     * @brief StDivision - Constructeur par defaut. Initialise :
     *         - l'identifiant en utilisant le nb de division
     *         - la note � LA (440hZ)
     *         - le volume au maximum, 100
     */
    StDivision();

    /**
     * @brief StDivision - Constructeur par recopie.
     *       Recopie les champs un � un.
     * @param copie
     */
    StDivision(const StDivision& copie);

    /**
     * @brief operator = - Op�rateur d'affectation. Recopie les valeurs.
     * @return la r�f�rence vers la nouvelle division.
     */
    StDivision& operator=(const StDivision&);

    /**
     * @brief setId - Initialise l'identifiant.
     * @param id le nouvel identifiant
     */
    inline void setId(int id){ this->id = id; }

    /**
     * @brief setNote - Initialise la note.
     * @param note le fr�quence de la note
     */
    inline void setNote(int note){ this->note = note; }

    /**
     * @brief setVolume - Initialise le volume
     * @param volume le volume de la division.
     */
    inline void setVolume(int volume){ this->volume = volume; }

    /**
     * @brief setSample - Initialise le sample
     * @param sample une r�f�rence vers le sample � jouer
     */
    void setSample(StSample* sample);

    /**
     * @brief getNbDivisions - Retourne le nombre de divisions.
     * @return le nombre de divisions
     */
    static inline int getNbDivisions(){ return nbDivisions; }

    /**
     * @brief getId - Retourne l'identifiant de la division.
     * @return l'identifiant de la division.
     */
    inline int getId() const { return id; }

    /**
     * @brief getNote - Retourne la note (fr�quence) � laquelle jouer la division.
     * @return la fr�quence de la note.
     */
    inline int getNote() const { return note; }

    /**
     * @brief getVolume - Retourne le volume de la division (0-10)
     * @return Le volume de la division.
     */
    inline int getVolume() const { return volume; }

    /**
     * @brief getSample - Retourne le pointeur vers le sample � jouer.
     * @return l'adresse du sample � jouer.
     */
    inline StSample* getSample() const { return sample; }

    /**
     * @brief isRepeat - Retourne l'etat de r�p�tition de la division.
     * @return l'etat de r�p�tition de la division.
     */
	bool isRepeat();

    /**      
     * @brief getNoteAsQString - Retourne la note sous forme de QString
     *       Exemple : 440 -> A2
     * @return le note sous forme de QString
     */
    QString getNoteAsQString();

    /**
     * @brief play - Commence la lecture de la division.
     */
	void play(bool);

	void debug();
};

#endif
