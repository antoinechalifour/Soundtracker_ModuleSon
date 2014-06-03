#ifndef _PATTERNH
#define _PATTERNH

#include "StDebug.h"
#include "StPiste.h"

/**
 * @brief Classe repr�sentant un Sample.
 * Un sample est caract�ris� par :
 * - id : son identifiant au sein du morceau
 * - nom : son nom
 * - pistes : un tableau de 8 pistes.
 * @author Antoine
 */
class StPattern{
private:
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
	static int nbPattern;
	int id;
    QString nom;
    StPiste pistes[8];

public:
    /*******************************************************************
     * Methodes
     * ****************************************************************/
    /**
     * @brief StPattern - Constructeur par d�faut.
     * Initialise l'identifiant.
     */
    StPattern();

    /**
     * @brief StPattern - Constructeur par recopie.
     */
    StPattern(const StPattern&);

    /**
     * @brief getNbPatterns - Retourne le nombre de patterns.
     * @return
     */
    static inline int getNbPatterns(){ return nbPattern; }

    /**
     * @brief getPiste - Retourne une r�f�rence vers la piste souhait�e.
     * @param index - le num�ro de la piste.
     * @return
     */
    StPiste& getPiste(int index);

    /**
     * @brief getID - Retourne l'identifiant.
     * @return l'identifiant.
     */
    inline int getID() const { return id; }

    /**
     * @brief getNom - Retourne le nom.
     * @return le nom.
     */
    inline QString getNom() const { return nom; }

    /**
     * @brief getPiste - Retourne une r�f�rence vers la piste.
     * @param index - le num�ro de la piste
     * @return la r�f�rence vers la piste.
     */
    inline StPiste& getPiste(int index) const {
        StPiste* pi = new StPiste(pistes[index]);
        return *pi;
    }

    /**
     * @brief setNom - Initialise le nom.
     * @param nom le nouceau nom.
     */
    void setNom(QString nom);

    /**
     * @brief setId  - Initialise l'identifiant.
     * @param id le nouvel identifiant.
     */
    inline void setId(int id){ this->id = id; }

    /**
     * @brief setPiste - Initialise la piste donn�e en param�tre.
     * @param piste La piste � affecter.
     * @param i le num�ro de la piste.
     */
    inline void setPiste(StPiste piste, int i){ pistes[i] = piste ; }

	void debug();
};

#endif
