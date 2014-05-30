#include "controleur.h"

Controleur::Controleur(IHMMainWindow* w,StMorceau* m):
    mw(w),
    morceau(m)
{
    samples.push_back(new StSample);
    samples.push_back(new StSample);
    ctrlSongEditor = new ControlleurSongEditor(morceau, mw->getSongEditor());
    ctrlSampleEditor = new ControlleurSampleEditor(samples, mw->getSampleEditor());
    ctrlPatternEditor = new ControlleurPatternEditor(patterns, mw->getPatternEditor());

    //connect(mw->getMenu()->getLoadSongButton(),SIGNAL(clicked()),this,SLOT(load()));
    QObject::connect(mw->getSongEditor()->getPatternSpinBox(), SIGNAL(valueChanged(int)), ctrlPatternEditor, SLOT(setPattern(int)));
}


void Controleur::load(){
    QString fileName = QFileDialog::getOpenFileName(mw,tr("MonTitre"),"Ordinateur", tr("Image Files (*.png *.jpg *.bmp)"));
}
