#ifndef _PATTERNH
#define _PATTERNH

#include "StDebug.h"
#include "StPiste.h"

/**
Classe repr�sentant un Sample.
Un sample est caract�ris� par :
- id : son identifiant au sein du morceau
- nom : son nom
- pistes : un tableau de 8 pistes.
 *@author Antoine
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
    StPattern();
    StPattern(const StPattern&);

    static inline int getNbPatterns(){ return nbPattern; }
    inline int getID(){ return id; }
    inline QString getNom(){ return nom; }
    StPiste& getPiste(int index);

    void setNom(QString nom);

    inline int getID() const { return id; }
    inline QString getNom() const { return nom; }

	void debug();
};

#endif
