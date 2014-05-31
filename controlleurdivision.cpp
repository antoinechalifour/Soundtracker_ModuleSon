#include "controlleurdivision.h"

ControlleurDivision::ControlleurDivision(int piste, int division, IHMDivision* panel, QObject *parent) :
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
}

void ControlleurDivision::changerSample(int value){
#ifdef STDEBUG
    cout<<"ControlleurDivision(piste="<<piste<<" div="<<division<<")::changerSample - valeur : "<<value<<endl;
#endif
}

void ControlleurDivision::changerVolume(int value){
#ifdef STDEBUG
    cout<<"ControlleurDivision(piste="<<piste<<" div="<<division<<")::changerVolume - valeur : "<<value<<endl;
#endif
    modele->getPiste(piste).getDivision(division).setVolume(value);
}
