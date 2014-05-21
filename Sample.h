#ifndef _SAMPLEH
#define _SAMPLEH
#include <string>
#include "ofSoundPlayer.h"

/*
Classe représentant un Sample.
Un sample est caractérisé par :
- id : son identifiant au sein du morceau
- nom : son nom
- volume : son volume (compris entre 1 et 100)
- repeat : booléen (à lire en boucle ou pas)
- repeatlen : la longueur à partie de laquelle il doit être répété
- pitch : sa hauteur (en hertz)
*/
class Sample{
private:
	/* --------------- ATTRIBUTS --------------- */
	static int nbSamples;
	int id;
	std::string nom;
	int volume;
	bool repeat;
	int repeatlen;
	int pitch;
	ofSoundPlayer *sound;

public:
	/* --------------- METHODES --------------- */
	/* CONSTRUCTEURS */
	Sample();
	Sample(const Sample&);

	/* GETTERS ET SETTERS */
	// Pas de set id -> generation automatique
	inline int getId(){ return id; };

	std::string getNom();
	void setNom(std::string nom);

	inline int getVolume(){ return volume; };
	inline void setVolume(int volume){ this->volume = volume; };

	inline bool isRepeat(){ return repeat; };
	void setRepeat(bool repeat);

	inline int getRepeatlen(){ return repeatlen; };
	inline void setRepeatlen(int repeatlen){ this->repeatlen = repeatlen; };

	inline int getPitch(){ return pitch; };
	inline void setPitch(int pitch){ this->pitch = pitch; };

	void setSound(std::string name);

	/* AUTRES METHODES */
	void play();
	void play(int note, int volume);
	void stop();

	/* METHODES STATIC */
	static inline int getNbSamples(){ return nbSamples; };

	/* DEBUG */
	void debug();
};

#endif