#include "controlleurdivision.h"

ControlleurDivision::ControlleurDivision(vector<StSample*> samples, int piste, int division, IHMDivision* panel, QObject *parent) :
    samples(samples),
    piste(piste),
    division(division),
    panel(panel),
    QObject(parent)
{
    this->connect();
}

void ControlleurDivision::connect(){
#ifdef STDEBUG
    //cout<<"ControlleurDivision::connect - connexion des elements graphiques"<<endl;
#endif
    QObject::connect(panel->getVolumeText(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getSampleText(), SIGNAL(valueChanged(int)), this, SLOT(changerSample(int)));
    QObject::connect(panel->getNoteText(), SIGNAL(textChanged(QString)), this, SLOT(changerNote(QString)));
}

void ControlleurDivision::disconnect(){
#ifdef STDEBUG
    //cout<<"ControlleurDivision::disconnect - deconnexion des elements graphiques"<<endl;
#endif
    QObject::disconnect(panel->getVolumeText(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::disconnect(panel->getSampleText(), SIGNAL(valueChanged(int)), this, SLOT(changerSample(int)));
    QObject::disconnect(panel->getNoteText(), SIGNAL(textChanged(QString)), this, SLOT(changerNote(QString)));
}

void ControlleurDivision::changerNote(QString note){
#ifdef STDEBUG
    cout<<"ControlleurDivision(piste="<<piste<<" div="<<division<<")::changerNote - valeur : "<<note.toStdString()<<endl;
#endif
    int freq=-1;
    if(note.toStdString() == "A") freq= FREQ_A;
    else if(note.toStdString() == "A#") freq= FREQ_AS;
    else if(note.toStdString() == "B") freq= FREQ_B;
    else if(note.toStdString() == "C") freq= FREQ_C;
    else if(note.toStdString() == "C#") freq= FREQ_CS;
    else if(note.toStdString() == "D") freq= FREQ_D;
    else if(note.toStdString() == "D#") freq= FREQ_DS;
    else if(note.toStdString() == "E") freq= FREQ_E;
    else if(note.toStdString() == "F") freq= FREQ_F;
    else if(note.toStdString() == "F#") freq= FREQ_FS;
    else if(note.toStdString() == "G") freq= FREQ_G;
    else if(note.toStdString() == "G#") freq= FREQ_GS;

    if(freq != -1) {
#ifdef STDEBUG
        cout<<"Modification de la note - freq= "<<freq<<endl;
#endif
        modele->getPiste(piste).getDivision(division).setNote(freq);
    }
}

void ControlleurDivision::changerSample(int value){
#ifdef STDEBUG
    cout<<"ControlleurDivision(piste="<<piste<<" div="<<division<<")::changerSample - valeur : "<<value<<endl;
#endif
    modele->getPiste(piste).getDivision(division).setSample(samples[value]);
}

void ControlleurDivision::changerVolume(int value){
#ifdef STDEBUG
    cout<<"ControlleurDivision(piste="<<piste<<" div="<<division<<")::changerVolume - valeur : "<<value<<endl;
#endif
    modele->getPiste(piste).getDivision(division).setVolume(value);
}
