#ifndef _DIVISIONH
#define _DIVISIONH

#include "StSample.h"
/**
 * @brief The StDivision class - Classe représentant une division.
 * Une division correspond à une unité de temps. Elle est caractérisée par :
 *     - une note (fréquence)
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
     *         - la note à LA (440hZ)
     *         - le volume au maximum, 100
     */
    StDivision();

    /**
     * @brief StDivision - Constructeur par recopie.
     *       Recopie les champs un à un.
     * @param copie
     */
    StDivision(const StDivision& copie);

    /**
     * @brief operator = - Opérateur d'affectation. Recopie les valeurs.
     * @return la référence vers la nouvelle division.
     */
    StDivision& operator=(const StDivision&);

    /**
     * @brief setId - Initialise l'identifiant.
     * @param id le nouvel identifiant
     */
    inline void setId(int id){ this->id = id; }

    /**
     * @brief setNote - Initialise la note.
     * @param note le fréquence de la note
     */
    inline void setNote(int note){ this->note = note; }

    /**
     * @brief setVolume - Initialise le volume
     * @param volume le volume de la division.
     */
    inline void setVolume(int volume){ this->volume = volume; }

    /**
     * @brief setSample - Initialise le sample
     * @param sample une référence vers le sample à jouer
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
     * @brief getNote - Retourne la note (fréquence) à laquelle jouer la division.
     * @return la fréquence de la note.
     */
    inline int getNote() const { return note; }

    /**
     * @brief getVolume - Retourne le volume de la division (0-10)
     * @return Le volume de la division.
     */
    inline int getVolume() const { return volume; }

    /**
     * @brief getSample - Retourne le pointeur vers le sample à jouer.
     * @return l'adresse du sample à jouer.
     */
    inline StSample* getSample() const { return sample; }

    /**
     * @brief isRepeat - Retourne l'etat de répétition de la division.
     * @return l'etat de répétition de la division.
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
