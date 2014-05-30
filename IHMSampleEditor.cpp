#include "IHMSampleEditor.h"

IHMSampleEditor::IHMSampleEditor(QWidget *parent) :
    QWidget(parent)
{
    panelTitle= new QLabel("SampleEditor");
    sampleName = new QLabel("Choix du sample : ");
    sampleNo = new QSpinBox;
    volumeLabel= new QLabel("Volume :");
    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSpinBox = new QSpinBox();
    pitchLabel= new QLabel("Pitch correct. :");
    pitchSlider = new QSlider(Qt::Horizontal);
    pitchSpinBox = new QSpinBox();
    repeatCheckBox = new QCheckBox("Repeat :");
    repeatLenLabel= new QLabel("Repeat Len. :");
    repeatSpinBox = new QSpinBox();

    boxSampleEdit = new QGridLayout(parent);

    boxSampleEdit->addWidget(sampleName,0,0, 1, 3);
    boxSampleEdit->addWidget(sampleNo, 0, 3);
    boxSampleEdit->addWidget(volumeLabel,1,0);
    boxSampleEdit->addWidget(volumeSlider,1,1,1,2);
    boxSampleEdit->addWidget(volumeSpinBox,1,3);
    boxSampleEdit->addWidget(pitchLabel,2,0);
    boxSampleEdit->addWidget(pitchSlider,2,1,1,2);
    boxSampleEdit->addWidget(pitchSpinBox,2,3);
    boxSampleEdit->addWidget(repeatCheckBox,3,0);
    boxSampleEdit->addWidget(repeatLenLabel,4,0);
    boxSampleEdit->addWidget(repeatSpinBox,4,1);


    setLayout(boxSampleEdit);

    setMaximumWidth(250);

}
