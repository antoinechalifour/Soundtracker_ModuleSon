#ifndef CONTROLLEURSAMPLEEDITOR_H
#define CONTROLLEURSAMPLEEDITOR_H

#include "StDebug.h"
#include "StSample.h"
#include "IHMSampleEditor.h"

class ControlleurSampleEditor : public QObject
{
    Q_OBJECT
private:
    StSample* modele;
    IHMSampleEditor* panel;

public:
    explicit ControlleurSampleEditor(StSample* modele, IHMSampleEditor* panel, QObject *parent = 0);

signals:

public slots:

};

#endif // CONTROLLEURSAMPLEEDITOR_H
