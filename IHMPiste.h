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
public:
    explicit IHMPiste(int numero,QWidget *parent = 0);

signals:

public slots:

};

#endif // PISTEIHM_H
