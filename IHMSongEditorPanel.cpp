#include "IHMSongEditorPanel.h"

IHMSongEditorPanel::IHMSongEditorPanel(QWidget *parent) :
    QWidget(parent)
{

    positionLabel = new QLabel("Position :");
    positionSpinBox = new QSpinBox();
    tempoLabel = new QLabel("Tempo :");
    tempoSpinBox = new QSpinBox();
    patternLabel = new QLabel("Pattern :");
    patternSpinBox = new QSpinBox();
    patLenLabel = new QLabel("Pat. Len. :");
    patLenghtSpinBox = new QSpinBox();
    masterLabel = new QLabel("Master :");
    masterSlider = new QSlider(Qt::Horizontal);
    masterSpinBox = new QSpinBox();
    stopButton= new QPushButton("Stop");
    playButton= new QPushButton("Play");

    boxSongEdit = new QGridLayout();

    boxSongEdit->addWidget(positionLabel,1,0);
    boxSongEdit->addWidget(positionSpinBox,1,1);
    boxSongEdit->addWidget(tempoLabel,1,2);
    boxSongEdit->addWidget(tempoSpinBox,1,3);
    boxSongEdit->addWidget(patternLabel,2,0);
    boxSongEdit->addWidget(patternSpinBox,2,1);
    boxSongEdit->addWidget(patLenLabel,3,0);
    boxSongEdit->addWidget(patLenghtSpinBox,3,1);
    boxSongEdit->addWidget(masterLabel,4,0);
    boxSongEdit->addWidget(masterSlider,4,1,1,2);
    boxSongEdit->addWidget(masterSpinBox,4,3);
    boxSongEdit->addWidget(playButton,5,0);
    boxSongEdit->addWidget(stopButton,5,1);





    setLayout(boxSongEdit);
    setMaximumWidth(250);

}

IHMSongEditorPanel::~IHMSongEditorPanel(){

    delete positionLabel;
    delete positionSpinBox;
    delete tempoLabel;
    delete tempoSpinBox;
    delete patternLabel;
    delete patternSpinBox;
    delete patLenLabel;
    delete patLenghtSpinBox;
    delete masterLabel;
    delete masterSlider;
    delete stopButton;
    delete playButton;
}

QPushButton* IHMSongEditorPanel::getPlayButton(){
    return playButton;
}
QPushButton* IHMSongEditorPanel::getStopButton(){
    return stopButton;
}

 QSpinBox* IHMSongEditorPanel::getPositionSpinBox(){
     return this->positionSpinBox;
 }

 QSpinBox* IHMSongEditorPanel::getPatternSpinBox(){
     return this->patternSpinBox;
 }

 QSlider* IHMSongEditorPanel::getMasterSlider(){
     return masterSlider;
 }

 QSpinBox* IHMSongEditorPanel::getMasterSpinBox(){
     return masterSpinBox;
 }
