#include "controlleurmenu.h"

ControlleurMenu::ControlleurMenu(ListeSample* samples, ListePattern* patterns, StMorceau* modele, IHMMainWindow* panel, QObject *parent) :
    samples(samples),
    patterns(patterns),
    modele(modele),
    panel(panel),
    QObject(parent)
{
    IHMMenuPanel* menu = panel->getMenu();
    QObject::connect(menu->getLoadSampleButton(), SIGNAL(clicked()), this, SLOT(loadSample()));
    QObject::connect(menu->getLoadSongButton(), SIGNAL(clicked()), this, SLOT(loadSong()));
    QObject::connect(menu->getSaveSongButton(), SIGNAL(clicked()), this, SLOT(saveSong()));
    QObject::connect(menu->getNewSongButton(), SIGNAL(clicked()), this, SLOT(newSong()));
}

void ControlleurMenu::loadSample(){
    QString fileName = QFileDialog::getOpenFileName(panel,tr("Sélectionnez un sample (.wav)"),"Sample.wav", tr("Sound files (*.wav)"));
    StSample* newSample = new StSample;
    newSample->setSound(fileName);
    samples->push_back(newSample);
}

void ControlleurMenu::loadSong(){
    QString fileName = QFileDialog::getOpenFileName(panel,tr("Sélectionnez un morceau"),"Morceau", tr("Soundtracker file (*.st)"));
    IOFile file(modele, patterns, samples);
    file.unserialize(fileName);
}

void ControlleurMenu::saveSong(){
    IOFile file(modele, patterns, samples);
    file.serialize();

}

void ControlleurMenu::newSong(){
}
