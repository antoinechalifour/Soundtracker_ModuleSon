#include "controleur.h"

Controleur::Controleur(IHMMainWindow* w,StMorceau* m):
    mw(w),
    morceau(m)
{
    StSample* s= new StSample;
    s->setSound("C:/Temp/guitarA.wav");
    StSample* s2 = new StSample;
    s2->setSound("C:/Temp/guitarD.wav");

    samples.push_back(s);
    samples.push_back(s2);
    ctrlSongEditor = new ControlleurSongEditor(morceau, &patterns, mw->getSongEditor());
    ctrlSampleEditor = new ControlleurSampleEditor(&samples, mw->getSampleEditor());
    ctrlPatternEditor = new ControlleurPatternEditor(morceau, &samples, &patterns, mw->getPatternEditor(), mw->getSongEditor());
    ctrlMenu = new ControlleurMenu(&samples, morceau, mw);

    QObject::connect(mw->getSongEditor()->getPatternSpinBox(), SIGNAL(valueChanged(int)), ctrlPatternEditor, SLOT(setPattern(int)));
}
