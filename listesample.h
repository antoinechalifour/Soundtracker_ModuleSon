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
    ListeSample(const ListeSample& copie);
    ListeSample& operator=(const ListeSample& copie);

    void push_back(StSample* element);
    inline StSample* at(int i) { return liste.at(i); }
    inline StSample* at(int i) const { return liste.at(i); }
    inline int size()const { return liste.size(); }
    inline bool empty()const { return liste.empty(); }

signals:
    void changed();

public slots:

};

#endif // LISTESAMPLE_H
