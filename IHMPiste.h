#ifndef PISTEIHM_H
#define PISTEIHM_H

#include "StDebug.h"
#include "IHMDivision.h"

class IHMPiste : public QWidget
{
    Q_OBJECT
private:
    QLabel* trackNum;
    QVBoxLayout* boxPiste;
    IHMDivision* divisions[64];
public:
    explicit IHMPiste(int numero,QWidget *parent = 0);
    inline IHMDivision* getDivision(int index){ return divisions[index]; }

signals:

public slots:

};

#endif // PISTEIHM_H
