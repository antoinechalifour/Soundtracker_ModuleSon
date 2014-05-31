#ifndef CONTROLLEURDIVISION_H
#define CONTROLLEURDIVISION_H

#include "StDebug.h"
#include "IHMDivision.h"
#include "StPattern.h"

class ControlleurDivision : public QObject
{
    Q_OBJECT
private:
    int piste;
    int division;
    IHMDivision* panel;
    StPattern* modele;

public:
    explicit ControlleurDivision(int piste, int division, IHMDivision* panel, QObject *parent = 0);
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
