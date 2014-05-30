#ifndef SAMPLEEDITORIHM_H
#define SAMPLEEDITORIHM_H

#include "StDebug.h"

class IHMSampleEditor : public QWidget
{
    Q_OBJECT
private:
    QLabel* panelTitle;
    QLabel* sampleName;
    QSpinBox* sampleNo;
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
    inline QSpinBox* getSampleNo(){ return sampleNo; }
    inline QSlider* getVolumeSlider(){ return volumeSlider; }
    inline QSpinBox* getVolumeSpinBox(){ return volumeSpinBox; }
    inline QSlider* getPitchSlider(){ return pitchSlider; }
    inline QSpinBox* getPitchSpinBox(){ return pitchSpinBox; }
    inline QCheckBox* getRepeatCheckBox(){ return repeatCheckBox; }
    inline QSpinBox* getRepeatSpinBox(){ return repeatSpinBox; }

signals:

public slots:

};

#endif // SAMPLEEDITORIHM_H
