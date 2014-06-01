#include "controleur.h"

Controleur::Controleur(IHMMainWindow* w,StMorceau* m):
    mw(w),
    morceau(m)
{
    StSample* s= new StSample;

    samples.push_back(s);
    ctrlSongEditor = new ControlleurSongEditor(morceau, &patterns, mw->getSongEditor());
    ctrlSampleEditor = new ControlleurSampleEditor(&samples, mw->getSampleEditor());
    ctrlPatternEditor = new ControlleurPatternEditor(morceau, &samples, &patterns, mw->getPatternEditor(), mw->getSongEditor());
    ctrlMenu = new ControlleurMenu(&samples, morceau, mw);

    QObject::connect(mw->getSongEditor()->getPatternSpinBox(), SIGNAL(valueChanged(int)), ctrlPatternEditor, SLOT(setPattern(int)));
    QObject::connect(morceau, SIGNAL(slot_indexLastPositionChanged()), ctrlSongEditor, SLOT(updatePosition()));
}
