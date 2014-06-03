#ifndef _PATTERNH
#define _PATTERNH

#include "StDebug.h"
#include "StPiste.h"

/**
 * @brief Classe représentant un Sample.
 * Un sample est caractérisé par :
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
     * @brief StPattern - Constructeur par défaut.
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
     * @brief getPiste - Retourne une référence vers la piste souhaitée.
     * @param index - le numéro de la piste.
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
     * @brief getPiste - Retourne une référence vers la piste.
     * @param index - le numéro de la piste
     * @return la référence vers la piste.
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
     * @brief setPiste - Initialise la piste donnée en paramètre.
     * @param piste La piste à affecter.
     * @param i le numéro de la piste.
     */
    inline void setPiste(StPiste piste, int i){ pistes[i] = piste ; }

	void debug();
};

#endif
