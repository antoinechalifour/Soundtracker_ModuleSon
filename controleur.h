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

class Controleur : public QObject
{
    Q_OBJECT
private:
    IHMMainWindow* mw;

    StMorceau* morceau;
    std::vector<StPattern*> patterns;
    std::vector<StSample*> samples;

    ControlleurSongEditor* ctrlSongEditor;
    ControlleurSampleEditor* ctrlSampleEditor;
    ControlleurPatternEditor* ctrlPatternEditor;

public:
    Controleur(IHMMainWindow *w,StMorceau *m);

public slots:
    void load();

};

#endif // CONTROLEUR_H
