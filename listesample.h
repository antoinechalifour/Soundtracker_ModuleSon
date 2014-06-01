#ifndef LISTESAMPLE_H
#define LISTESAMPLE_H

#include "StDebug.h"
#include "StSample.h"

class ListeSample : public QObject
{
    Q_OBJECT
private:
    QVector<StSample*> liste;

public:
    explicit ListeSample(QObject *parent = 0);
    void push_back(StSample* element);
    inline StSample* at(int i) { return liste.at(i); }
    inline int size(){ return liste.size(); }
    inline bool empty(){ return liste.empty(); }

signals:
    void changed();

public slots:

};

#endif // LISTESAMPLE_H
