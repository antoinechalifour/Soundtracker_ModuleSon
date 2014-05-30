#ifndef SONGEDITORPANELIHM_H
#define SONGEDITORPANELIHM_H

#include "StDebug.h"

class IHMSongEditorPanel : public QWidget
{
    Q_OBJECT
private:
    QLabel*     positionLabel;
    QSpinBox*   positionSpinBox;
    QLabel*     tempoLabel;
    QSpinBox*   tempoSpinBox;
    QLabel*     patternLabel;
    QSpinBox*   patternSpinBox;
    QLabel*     patLenLabel;
    QSpinBox*   patLenghtSpinBox;
    QLabel*     masterLabel;
    QSlider*    masterSlider;
    QSpinBox*   masterSpinBox;
    QPushButton*  playButton;
    QPushButton*  stopButton;
    QGridLayout*  boxSongEdit;

public:
    explicit IHMSongEditorPanel(QWidget *parent = 0);
    ~IHMSongEditorPanel();
    QPushButton* getPlayButton();
    QPushButton* getStopButton();
    QSpinBox* getPositionSpinBox();
    QSpinBox* getPatternSpinBox();
    QSlider* getMasterSlider();
    QSpinBox* getMasterSpinBox();
signals:

public slots:

};

#endif // SONGEDITORPANELIHM_H
