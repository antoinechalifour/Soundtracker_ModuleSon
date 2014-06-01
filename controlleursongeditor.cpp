#include "controlleursongeditor.h"

ControlleurSongEditor::ControlleurSongEditor(StMorceau* modele, ListePattern* patterns, IHMSongEditorPanel* panel, QObject *parent) :
    QObject(parent),
    modele(modele),
    patterns(patterns),
    panel(panel)
{
    panel->getPositionSpinBox()->setMaximum(modele->getLastPosition()+1);
    panel->getTempoSpinBox()->setValue(96);
    panel->getTempoSpinBox()->setMaximum(350);
    panel->getMasterSlider()->setValue(100);
    panel->getMasterSpinBox()->setValue(100);
    panel->getMasterSlider()->setMinimum(0);
    panel->getMasterSpinBox()->setMinimum(0);
    panel->getMasterSlider()->setMaximum(100);
    panel->getMasterSpinBox()->setMaximum(100);

    panel->getStopButton()->setEnabled(false);

    QObject::connect(panel->getMasterSlider(), SIGNAL(valueChanged(int)), panel->getMasterSpinBox(), SLOT(setValue(int)));
    QObject::connect(panel->getMasterSpinBox(), SIGNAL(valueChanged(int)), panel->getMasterSlider(), SLOT(setValue(int)));
    QObject::connect(panel->getPlayButton(), SIGNAL(clicked()), this, SLOT(play()));
    QObject::connect(panel->getStopButton(), SIGNAL(clicked()), this, SLOT(stop()));

    QObject::connect(panel->getMasterSlider(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getMasterSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getTempoSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerTempo(int)));
}


void ControlleurSongEditor::play(){
    cout<<"Lecture du morceau ..."<<endl;
    panel->getPlayButton()->setEnabled(false);
    panel->getStopButton()->setEnabled(true);
    modele->lecture(true, 0, 0);
}

void ControlleurSongEditor::stop(){
    cout<<"Stop du morceau..."<<endl;
    panel->getPlayButton()->setEnabled(true);
    panel->getStopButton()->setEnabled(false);
    modele->lecture(false, 0, 0);
}

void ControlleurSongEditor::changerPattern(int value){
#ifdef STDEBUG
    cout<<"ControlleurSongEditor::changerPattern - valeur : "<<value<<endl;
#endif
    StPattern* tmp = patterns->at(value);
    modele->affecterPattern(panel->getPositionSpinBox()->value(), tmp);
}

void ControlleurSongEditor::changerTempo(int value){
#ifdef STDEBUG
    cout<<"ControlleurSongEditor::changerTempo - valeur : "<<value<<endl;
#endif
    modele->setTempo(value);
}

void ControlleurSongEditor::changerVolume(int value){
#ifdef STDEBUG
    cout<<"ControlleurSongEditor::changerVolume - valeur : "<<value<<endl;
#endif
    modele->setVolume(value);
}

void ControlleurSongEditor::updatePosition(){
    panel->getPositionSpinBox()->setMaximum(modele->getLastPosition());
}
