#ifndef CONTROLLEURDIVISION_H
#define CONTROLLEURDIVISION_H

#include "StDebug.h"
#include "IHMDivision.h"
#include "StPattern.h"
#include "StSample.h"
#include "listesample.h"

class ControlleurDivision : public QObject
{
    Q_OBJECT
private:
    int piste;
    int division;
    IHMDivision* panel;
    StPattern* modele;
    ListeSample* samples;

public:
    explicit ControlleurDivision(ListeSample* samples, int piste, int division, IHMDivision* panel, QObject *parent = 0);
    inline void setPattern(StPattern* pattern){
        this->modele = pattern;
    }
    void connect();
    void disconnect();

signals:

public slots:
    void changerVolume(int);
    void changerNote(QString);
    void changerSample(int);

};

#endif // CONTROLLEURDIVISION_H
