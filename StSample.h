#ifndef _SAMPLEH
#define _SAMPLEH

#include "StDebug.h"

/**
Classe représentant un Sample.
Un sample est caractérisé par :
- id : son identifiant au sein du morceau
- nom : son nom
- volume : son volume (compris entre 1 et 100)
- repeat : booléen (à lire en boucle ou pas)
- repeatlen : la longueur à partie de laquelle il doit être répété
- pitch : sa hauteur (en hertz)

 *@author Antoine
*/

class StSample{
private:
    /*******************************************************************
     * ATTRIBUTS
     * ****************************************************************/
	static int nbSamples;
	int id;
    QString nom;
	int volume;
	bool repeat;
	int repeatlen;
	int pitch;
    QMediaPlayer *sound;
    //QSoundEffect* sound;

public:
    /*******************************************************************
     * METHODES
     * ****************************************************************/
    StSample();
    StSample(const StSample&);

    void setNom(QString nom);
    inline void setId(int id){ this->id = id; }
    inline void setVolume(int volume){ this->volume = volume; }
    void setRepeat(bool repeat);
    inline void setRepeatlen(int repeatlen){ this->repeatlen = repeatlen; }
    inline void setPitch(int pitch){ this->pitch = pitch; }
    void setSound(QString name);

    static inline int getNbSamples(){ return nbSamples; }
    inline int getId(){ return id; }
    inline QString getNom(){ return nom; }
    inline int getVolume(){ return volume; }
    inline bool isRepeat(){ return repeat; }
    inline int getRepeatlen(){ return repeatlen; }
    inline int getPitch(){ return pitch; }

    inline int getId() const { return id; }
    inline QString getNom() const { return nom; }
    inline int getVolume() const { return volume; }
    inline bool isRepeat() const { return repeat; }
    inline int getRepeatlen() const { return repeatlen; }
    inline int getPitch() const { return pitch; }

	void play();
	void play(int note, int volume);
	void stop();

	void debug();
};

#endif
