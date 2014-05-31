#include "controlleurpatterneditor.h"

ControlleurPatternEditor::ControlleurPatternEditor(StMorceau* modele, vector<StSample*> samples, vector<StPattern*> patterns, IHMPatternEditorPanel* panel, IHMSongEditorPanel* songpanel, QObject *parent):
    modele(modele),
    samples(samples),
    patterns(patterns),
    panel(panel),
    songpanel(songpanel),
    QObject(parent)
{
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<64 ; j++){
            ctrlsDivision[i][j] = new ControlleurDivision(samples, i, j, panel->getPiste(i)->getDivision(j));
        }
    }
    setPattern(0);
}

void ControlleurPatternEditor::setPattern(int value){
#ifdef STDEBUG
    cout<<"ControlleurPatternEditor::setPattern - valeur : "<<value<<endl;
#endif
    if(value < patterns.size()){
        //maj
        current = patterns[value];
    }
    else{
        //creation;
        StPattern* pattern = new StPattern;
        patterns.push_back(pattern);
        current = pattern;
    }
    //Affectation du pattern
    modele->affecterPattern(songpanel->getPositionSpinBox()->value(), current);

    //Affichage des informations
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<64 ; j++){
            StSample* tmp = current->getPiste(i).getDivision(j).getSample();
            ctrlsDivision[i][j]->setPattern(current);
            ctrlsDivision[i][j]->disconnect();
            if(tmp == NULL){
                panel->getPiste(i)->getDivision(j)->getSampleText()->setValue(-1);
                panel->getPiste(i)->getDivision(j)->getVolumeText()->setValue(4);
                panel->getPiste(i)->getDivision(j)->getNoteText()->setText("---");
            }
            else{
                panel->getPiste(i)->getDivision(j)->getSampleText()->setValue(current->getPiste(i).getDivision(j).getSample()->getId());
                panel->getPiste(i)->getDivision(j)->getVolumeText()->setValue(current->getPiste(i).getDivision(j).getVolume());
                panel->getPiste(i)->getDivision(j)->getNoteText()->setText(current->getPiste(i).getDivision(j).getNoteAsQString());
            }
            ctrlsDivision[i][j]->connect();
        }
    }
}
