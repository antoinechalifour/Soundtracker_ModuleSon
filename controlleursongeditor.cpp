#include "controlleursongeditor.h"

ControlleurSongEditor::ControlleurSongEditor(StMorceau* modele, IHMSongEditorPanel* panel, QObject *parent) :
    modele(modele),
    panel(panel),
    QObject(parent)
{
    panel->getMasterSlider()->setValue(50);
    panel->getMasterSpinBox()->setValue(50);
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
    // try and catch affecter pattern : affectation impossible de la possition 36 si pas de 35
  // this->morceau->affecterPattern(this->mw->getSongEditor()->getPositionSpinBox()->value(),patterns[value]);
   cout << "affecterPattern(" << panel->getPositionSpinBox()->value()<< "," << value <<")" << endl;
}
