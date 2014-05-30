#include "controleur.h"

Controleur::Controleur(IHMMainWindow* w,StMorceau* m):
    mw(w),
    morceau(m)
{
    samples.push_back(new StSample);
    samples.push_back(new StSample);
    ctrlSongEditor = new ControlleurSongEditor(morceau, mw->getSongEditor());
    ctrlSampleEditor = new ControlleurSampleEditor(samples, mw->getSampleEditor());

    connect(mw->getMenu()->getLoadSongButton(),SIGNAL(clicked()),this,SLOT(load()));
}


void Controleur::load(){
    QString fileName = QFileDialog::getOpenFileName(mw,tr("MonTitre"),"Ordinateur", tr("Image Files (*.png *.jpg *.bmp)"));
}

//void Controleur::master();
