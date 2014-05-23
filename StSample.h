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

public:
    /*******************************************************************
     * METHODES
     * ****************************************************************/
    StSample();
    StSample(const StSample&);

    static inline int getNbSamples(){ return nbSamples; }
    inline int getId(){ return id; }
    QString getNom();
    void setNom(QString nom);
    inline int getVolume(){ return volume; }
    inline void setVolume(int volume){ this->volume = volume; }
    inline bool isRepeat(){ return repeat; }
	void setRepeat(bool repeat);
    inline int getRepeatlen(){ return repeatlen; }
    inline void setRepeatlen(int repeatlen){ this->repeatlen = repeatlen; }
    inline int getPitch(){ return pitch; }
    inline void setPitch(int pitch){ this->pitch = pitch; }
    void setSound(QString name);

	void play();
	void play(int note, int volume);
	void stop();

	void debug();
};

#endif
