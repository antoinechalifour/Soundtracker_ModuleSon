#ifndef LISTEPATTERN_H
#define LISTEPATTERN_H

#include "StDebug.h"
#include "StPattern.h"

class ListePattern : public QObject
{
    Q_OBJECT
private:
    QVector<StPattern*> liste;

public:
    explicit ListePattern(QObject *parent = 0);
    void push_back(StPattern* element);
    inline StPattern* at(int i) { return liste.at(i); }
    inline int size(){ return liste.size(); }
    inline bool empty(){ return liste.empty(); }

signals:
    void changed();

public slots:

};

#endif // LISTEPATTERN_H
