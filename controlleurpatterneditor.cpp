#include "controlleurpatterneditor.h"

ControlleurPatternEditor::ControlleurPatternEditor(vector<StPattern*> patterns, IHMPatternEditorPanel* panel, QObject *parent):
    patterns(patterns),
    panel(panel),
    QObject(parent)
{
    setPattern(0);
}

void ControlleurPatternEditor::setPattern(int value){
#ifdef STDEBUG
    cout<<"ControlleurPatternEditor::setPattern - valeur : "<<value<<endl;
#endif
    if(value < patterns.size()){
        //maj
    }
    else{
        //creation;
        StPattern* pattern = new StPattern;
        patterns.push_back(pattern);
        current = pattern;
    }

    for(int i=0 ; i<8 ; i++){
        for(int i=0 ; j<64 ; j++){
            panel->getPiste(i)->getDivision(j);
        }
    }
}
