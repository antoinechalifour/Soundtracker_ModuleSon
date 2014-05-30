#include "IHMDivision.h"

IHMDivision::IHMDivision(int numero, QWidget *parent) :
    QWidget(parent)
{

    divNum = new QLabel(QString().setNum(numero));

    noteText = new QLineEdit("--");
    sampleText = new QSpinBox();
    volumeText = new QSpinBox();

    noteText->setMaxLength(2);
    noteText->setFixedWidth(40);
    sampleText->setMaximum(999);
    volumeText->setMaximum(100);

    boxDiv = new QHBoxLayout(parent);
    boxDiv->addWidget(divNum);
    boxDiv->addWidget(noteText);
    boxDiv->addWidget(sampleText);
    boxDiv->addWidget(volumeText);

    setLayout(boxDiv);

}
