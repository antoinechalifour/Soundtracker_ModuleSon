#include "IHMPiste.h"

IHMPiste::IHMPiste(int numero, QWidget *parent) :
    QWidget(parent)
{
    boxPiste = new QVBoxLayout(parent);

    trackNum = new QLabel(tr("Track #")+QString().setNum(numero));

    boxPiste->addWidget(trackNum);

    for (int i = 0;  i < 64; i++){
        divisions[i] = new IHMDivision(i+1);
        boxPiste->addWidget(divisions[i]);
    }

    setLayout(boxPiste);
}
