#ifndef CONTROLLEURPATTERNEDITOR_H
#define CONTROLLEURPATTERNEDITOR_H

#include "StDebug.h"
#include "StPattern.h"
#include "StMorceau.h"
#include "IHMPatternEditorPanel.h"
#include "IHMSongEditorPanel.h"
#include "controlleurdivision.h"

class ControlleurPatternEditor : public QObject
{
    Q_OBJECT
private:
    vector<StPattern*> patterns;
    IHMPatternEditorPanel* panel;
    IHMSongEditorPanel* songpanel;
    StPattern* current;
    StMorceau* modele;
    ControlleurDivision* ctrlsDivision[8][64];

public:
    explicit ControlleurPatternEditor(StMorceau* modele, vector<StPattern*> patterns, IHMPatternEditorPanel* panel, IHMSongEditorPanel* songpanel, QObject *parent = 0);

signals:

public slots:
    void setPattern(int);

};

#endif // CONTROLLEURPATTERNEDITOR_H
