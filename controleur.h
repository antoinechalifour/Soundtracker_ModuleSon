#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "stdebug.h"
#include "IHMMainWindow.h"
#include "StMorceau.h"
#include "StPattern.h"
#include "StSample.h"
#include "controlleursongeditor.h"
#include "controlleursampleeditor.h"
#include "controlleurpatterneditor.h"
#include "controlleurmenu.h"
#include "listesample.h"
#include "listepattern.h"

class Controleur : public QObject
{
    Q_OBJECT
private:
    IHMMainWindow* mw;

    StMorceau* morceau;
    ListePattern patterns;
    ListeSample samples;

    ControlleurSongEditor* ctrlSongEditor;
    ControlleurSampleEditor* ctrlSampleEditor;
    ControlleurPatternEditor* ctrlPatternEditor;
    ControlleurMenu* ctrlMenu;

public:
    Controleur(IHMMainWindow *w,StMorceau *m);

public slots:

};

#endif // CONTROLEUR_H
