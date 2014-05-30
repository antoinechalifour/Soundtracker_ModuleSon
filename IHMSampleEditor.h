#ifndef SAMPLEEDITORIHM_H
#define SAMPLEEDITORIHM_H

#include "StDebug.h"

class IHMSampleEditor : public QWidget
{
    Q_OBJECT
private:
    QLabel* panelTitle;
    QLabel* volumeLabel;
    QSlider* volumeSlider;
    QSpinBox* volumeSpinBox;
    QLabel* pitchLabel;
    QSlider* pitchSlider;
    QSpinBox* pitchSpinBox;
    QLabel* repeatLenLabel;
    QCheckBox* repeatCheckBox;
    QSpinBox* repeatSpinBox;
    QGridLayout* boxSampleEdit;
public:
    explicit IHMSampleEditor(QWidget *parent = 0);

signals:

public slots:

};

#endif // SAMPLEEDITORIHM_H
