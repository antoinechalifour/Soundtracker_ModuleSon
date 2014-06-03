#ifndef _MORCEAUH
#define _MORCEAUH

#include "StDebug.h"
#include "StPosition.h"
#include "StDivision.h"
#include "StPattern.h"

/**
 * @brief Classe repr�sentant le morceau.
 * Un morceau est caract�ris� par :
 * - nom : son nom
 * - tempo : son tempo (sup�rieur � 0)
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
     * @brief StMorceau - Constructeur par d�faut.
     * Initialise :
     *  - le tempo � 96
     *  - le nom � "Morceau.st"
     */
    StMorceau();

    /**
     * @brief StMorceau - Constructeur par recopie.
     * @param copie un autre morceau.
     */
    StMorceau(const StMorceau& copie);

    /**
     * @brief operator = - op�rateur d'affectation.
     * @param copie - un autre morceau.
     * @return une r�f�rence vers le morceau.
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
     * @brief getPosition - Retourne une r�f�rence vers la position donn�e en param�tre.
     * @param i l'index de la position.
     * @return la r�f�rence vers la position.
     */
    inline StPosition& getPosition(int i){ return positions[i]; }

    /**
     * @brief getDivision - Retourne une r�f�rence vers la division indiqu�e en param�tre.
     * @param pattern le pattern de la division.
     * @param piste la piste de la division.
     * @param division le num�ro de la division.
     * @return la r�f�rence vers la division.
     */
    StDivision& getDivision(StPattern* pattern, int piste, int division);

    /**
     * @brief getLastPosition - Retourne le num�ro de la derni�re position affect�e.
     * @return le num�ro de la derni�re position.
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
     * @brief getPosition - Retourne une r�f�rence vers la position souhait�e.
     * @param i le num�ro de la position.
     * @return une r�f�rence vers la position souhait�e.
     */
    inline StPosition& getPosition(int i) const {
        StPosition* tmp = new StPosition(positions[i]);
        return *tmp;
    }

    /**
     * @brief getIndexLastPosition - Retourne l'index de la derni�re position.
     * @return l'index de la derni�re position.
     */
    inline int getIndexLastPosition() const { return indexLastPosition; }

    /**
     * @brief lecture - Lis le morceau (bool=true) � partir de la position et de la division donn�es.
     *       Stop la lecture (bool=false).
     * @param lect lecture/stop
     * @param position la position de d�part
     * @param division la division de d�part
     */
    void lecture(bool lect, int position, int division);

    /**
     * @brief affecterPattern - Affecte un pattern � une position donn�e.
     * @param position le num�ro de position
     * @param pattern un pointeur vers le pattern.
     */
    void affecterPattern(int position, StPattern* pattern);

	void debug();

signals:
    /**
     * @brief slot_indexLastPositionChanged - Signal envoy� lorsque la derni�re position est chang�e.
     */
    void slot_indexLastPositionChanged();

public slots:
    /**
     * @brief slot_play - Lance la lecture (utilise QTimer).
     */
    void slot_play();
};
#endif
