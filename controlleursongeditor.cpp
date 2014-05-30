#include "controlleursongeditor.h"

ControlleurSongEditor::ControlleurSongEditor(StMorceau* modele, IHMSongEditorPanel* panel, QObject *parent) :
    modele(modele),
    panel(panel),
    QObject(parent)
{
    panel->getPositionSpinBox()->setMaximum(modele->getLastPosition());
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
    QObject::connect(panel->getPatternSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerPattern(int)));

    QObject::connect(panel->getMasterSlider(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getMasterSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getTempoSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerTempo(int)));
}


void ControlleurSongEditor::play(){
    cout<<"Lecture du morceau ..."<<endl;
    panel->getPlayButton()->setEnabled(false);
    panel->getStopButton()->setEnabled(true);
}

void ControlleurSongEditor::stop(){
    cout<<"Stop du morceau..."<<endl;
    panel->getPlayButton()->setEnabled(true);
    panel->getStopButton()->setEnabled(false);
}


void ControlleurSongEditor::changerPattern(int value){
   cout << "affecterPattern(" << panel->getPositionSpinBox()->value()<< "," << value <<")" << endl;
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
