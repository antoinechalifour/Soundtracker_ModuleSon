#ifndef DIVISIONSIHM_H
#define DIVISIONSIHM_H

#include "StDebug.h"

class IHMDivision : public QWidget
{
    Q_OBJECT
private: 
    QLabel* divNum;
    QLineEdit* noteText;
    QSpinBox* sampleText;
    QSpinBox* volumeText;
    QHBoxLayout* boxDiv;
public:
    explicit IHMDivision(int numero,QWidget *parent = 0);
    inline QLineEdit* getNoteText(){ return noteText; }
    inline QSpinBox* getSampleText(){ return sampleText; }
    inline QSpinBox* getVolumeText(){ return volumeText; }

signals:

public slots:

};

#endif // DIVISIONSIHM_H
