#ifndef _MORCEAUH
#define _MORCEAUH

#include "StDebug.h"
#include "StPosition.h"
#include "StDivision.h"
#include "StPattern.h"

/**
 * @brief Classe représentant le morceau.
 * Un morceau est caractérisé par :
 * - nom : son nom
 * - tempo : son tempo (supérieur à 0)
 * - volume son volume (compris entre 1 et 100)
 * @author Antoine
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
    /**
     * @brief StMorceau - Constructeur par défaut.
     * Initialise :
     *  - le tempo à 96
     *  - le nom à "Morceau.st"
     */
    StMorceau();

    /**
     * @brief StMorceau - Constructeur par recopie.
     * @param copie un autre morceau.
     */
    StMorceau(const StMorceau& copie);

    /**
     * @brief operator = - opérateur d'affectation.
     * @param copie - un autre morceau.
     * @return une référence vers le morceau.
     */
    StMorceau& operator=(const StMorceau& copie);

    /**
     * @brief getNom - Retourne le nom du morceau.
     * @return le nom du morceau.
     */
    inline QString getNom() { return nom; }

    /**
     * @brief getTempo - Retourne le tempo du morceau.
     * @return le tempo du morceau.
     */
    inline int getTempo() { return tempo; }

    /**
     * @brief getVolume - Retourne le volume du morceau.
     * @return le volume du morceau.
     */
    inline int getVolume() { return volume; }

    /**
     * @brief getPosition - Retourne une référence vers la position donnée en paramètre.
     * @param i l'index de la position.
     * @return la référence vers la position.
     */
    inline StPosition& getPosition(int i){ return positions[i]; }

    /**
     * @brief getDivision - Retourne une référence vers la division indiquée en paramètre.
     * @param pattern le pattern de la division.
     * @param piste la piste de la division.
     * @param division le numéro de la division.
     * @return la référence vers la division.
     */
    StDivision& getDivision(StPattern* pattern, int piste, int division);

    /**
     * @brief getLastPosition - Retourne le numéro de la dernière position affectée.
     * @return le numéro de la dernière position.
     */
    inline int getLastPosition(){ return indexLastPosition+1; }

    /**
     * @brief setNom - Initialise le nom.
     * @param nom le nouveau nom.
     */
    void setNom(QString nom);

    /**
     * @brief setTempo - Initialise le tempo.
     * @param tempo le nouveau tempo.
     */
    inline void setTempo(int tempo){ this->tempo = tempo; }

    /**
     * @brief setVolume - Initialise le volume.
     * @param volume le nouveau volume.
     */
    inline void setVolume(int volume){ this->volume = volume; }

    /**
     * @brief getNom - Retourne le nom.
     * @return le nom
     */
    inline QString getNom() const { return nom; }

    /**
     * @brief getTempo - Retourne le tempo.
     * @return le tempo.
     */
    inline int getTempo() const { return tempo; }

    /**
     * @brief getVolume - Retourne le volume.
     * @return le volume.
     */
    inline int getVolume() const { return volume; }

    /**
     * @brief getPosition - Retourne une référence vers la position souhaitée.
     * @param i le numéro de la position.
     * @return une référence vers la position souhaitée.
     */
    inline StPosition& getPosition(int i) const {
        StPosition* tmp = new StPosition(positions[i]);
        return *tmp;
    }

    /**
     * @brief getIndexLastPosition - Retourne l'index de la dernière position.
     * @return l'index de la dernière position.
     */
    inline int getIndexLastPosition() const { return indexLastPosition; }

    /**
     * @brief lecture - Lis le morceau (bool=true) à partir de la position et de la division données.
     *       Stop la lecture (bool=false).
     * @param lect lecture/stop
     * @param position la position de départ
     * @param division la division de départ
     */
    void lecture(bool lect, int position, int division);

    /**
     * @brief affecterPattern - Affecte un pattern à une position donnée.
     * @param position le numéro de position
     * @param pattern un pointeur vers le pattern.
     */
    void affecterPattern(int position, StPattern* pattern);

	void debug();

signals:
    /**
     * @brief slot_indexLastPositionChanged - Signal envoyé lorsque la dernière position est changée.
     */
    void slot_indexLastPositionChanged();

public slots:
    /**
     * @brief slot_play - Lance la lecture (utilise QTimer).
     */
    void slot_play();
};
#endif
