#include "controlleursampleeditor.h"

ControlleurSampleEditor::ControlleurSampleEditor(ListeSample* modele, IHMSampleEditor* panel, QObject *parent) :
    modele(modele),
    panel(panel),
    QObject(parent)
{
    panel->getSampleNo()->setMinimum(0);

    panel->getVolumeSlider()->setMinimum(0);
    panel->getVolumeSlider()->setMaximum(100);
    panel->getVolumeSpinBox()->setMinimum(0);
    panel->getVolumeSpinBox()->setMaximum(100);

    panel->getPitchSlider()->setMinimum(-50);
    panel->getPitchSlider()->setMaximum(50);
    panel->getPitchSpinBox()->setMinimum(-50);
    panel->getPitchSpinBox()->setMaximum(50);

    if(modele->empty()){
        panel->getVolumeSlider()->setValue(100);
        panel->getVolumeSpinBox()->setValue(100);

        panel->getPitchSlider()->setValue(0);
        panel->getPitchSpinBox()->setValue(0);
        panel->getSampleNo()->setMaximum(0);
    }
    else{
        panel->getSampleNo()->setMaximum(StSample::getNbSamples()-1);
        setSample(0);
    }

    QObject::connect(panel->getSampleNo(), SIGNAL(valueChanged(int)), this, SLOT(setSample(int)));
    QObject::connect(panel->getVolumeSlider(), SIGNAL(valueChanged(int)), panel->getVolumeSpinBox(), SLOT(setValue(int)));
    QObject::connect(panel->getVolumeSpinBox(), SIGNAL(valueChanged(int)), panel->getVolumeSlider(), SLOT(setValue(int)));
    QObject::connect(panel->getPitchSlider(), SIGNAL(valueChanged(int)), panel->getPitchSpinBox(), SLOT(setValue(int)));
    QObject::connect(panel->getPitchSpinBox(), SIGNAL(valueChanged(int)), panel->getPitchSlider(), SLOT(setValue(int)));
    QObject::connect(panel->getVolumeSlider(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getVolumeSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerVolume(int)));
    QObject::connect(panel->getPitchSlider(), SIGNAL(valueChanged(int)), this, SLOT(changerPitch(int)));
    QObject::connect(panel->getPitchSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerPitch(int)));
    QObject::connect(panel->getRepeatCheckBox(), SIGNAL(clicked(bool)), this, SLOT(changerRepeat(bool)));
    QObject::connect(panel->getRepeatSpinBox(), SIGNAL(valueChanged(int)), this, SLOT(changerRepeatLen(int)));

    QObject::connect(modele, SIGNAL(changed()), this, SLOT(updateNewSample()));
}

void ControlleurSampleEditor::setSample(int value){
#ifdef STDEBUG
    cout<<"ControlleurSampleEditor::setSample - valeur : "<<value<<endl;
#endif
    current = modele->at(value);
    panel->getVolumeSlider()->setValue(current->getVolume());
    panel->getVolumeSpinBox()->setValue(current->getVolume());

    panel->getPitchSlider()->setValue(current->getPitch());
    panel->getPitchSpinBox()->setValue(current->getPitch());

    panel->getRepeatCheckBox()->setChecked(current->isRepeat());
    panel->getRepeatSpinBox()->setValue(current->getRepeatlen());
}

void ControlleurSampleEditor::changerPitch(int value){
#ifdef STDEBUG
    cout<<"ControlleurSampleEditor::changerPitch - valeur : "<<value<<endl;
#endif
    current->setPitch(value);
}

void ControlleurSampleEditor::changerVolume(int value){
#ifdef STDEBUG
    cout<<"ControlleurSampleEditor::changerVolume - valeur : "<<value<<endl;
#endif
    current->setVolume(value);
}

void ControlleurSampleEditor::changerRepeat(bool value){
#ifdef STDEBUG
    cout<<"ControlleurSampleEditor::changerRepeat - valeur : "<<value<<endl;
#endif
    current->setRepeat(value);
}

void ControlleurSampleEditor::changerRepeatLen(int value){
#ifdef STDEBUG
    cout<<"ControlleurSampleEditor::changerRepeatLen - valeur : "<<value<<endl;
#endif
    current->setRepeatlen(value);
}

void ControlleurSampleEditor::updateNewSample(){
#ifdef STDEBUG
    cout<<"ControlleurSampleEditor::updateNewSample"<<endl;
#endif
    panel->getSampleNo()->setMaximum(modele->size());
}
