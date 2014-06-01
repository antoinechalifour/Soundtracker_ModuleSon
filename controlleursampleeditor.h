#ifndef CONTROLLEURSAMPLEEDITOR_H
#define CONTROLLEURSAMPLEEDITOR_H

#include "StDebug.h"
#include "StSample.h"
#include "IHMSampleEditor.h"
#include "listesample.h"

class ControlleurSampleEditor : public QObject
{
    Q_OBJECT
private:
    ListeSample* modele;
    IHMSampleEditor* panel;
    StSample* current;

public:
    explicit ControlleurSampleEditor(ListeSample* modele, IHMSampleEditor* panel, QObject *parent = 0);

signals:

public slots:
    void setSample(int);
    void changerVolume(int);
    void changerPitch(int);
    void changerRepeat(bool);
    void changerRepeatLen(int);
    void updateNewSample();

};

#endif // CONTROLLEURSAMPLEEDITOR_H
