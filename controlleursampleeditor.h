#ifndef CONTROLLEURSAMPLEEDITOR_H
#define CONTROLLEURSAMPLEEDITOR_H

#include "StDebug.h"
#include "StSample.h"
#include "IHMSampleEditor.h"

class ControlleurSampleEditor : public QObject
{
    Q_OBJECT
private:
    vector<StSample*> modele;
    IHMSampleEditor* panel;
    StSample* current;

public:
    explicit ControlleurSampleEditor(vector<StSample*> modele, IHMSampleEditor* panel, QObject *parent = 0);

signals:

public slots:
    void setSample(int);
    void changerVolume(int);
    void changerPitch(int);
    void changerRepeat(bool);
    void changerRepeatLen(int);

};

#endif // CONTROLLEURSAMPLEEDITOR_H
