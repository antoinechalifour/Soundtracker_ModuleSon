#ifndef IOFILE_H
#define IOFILE_H

#include "StDebug.h"
#include "StMorceau.h"
#include "StPosition.h"
#include "StPattern.h"
#include "StPiste.h"
#include "StDivision.h"
#include "StSample.h"
#include "listepattern.h"
#include "listesample.h"

class IOFile
{
private:
    StMorceau* morceau;
    ListePattern* patterns;
    ListeSample* samples;
public:
    IOFile(StMorceau* morceau, ListePattern* patterns, ListeSample* samples);
    void serialize();
    void unserialize(QString fileName);
};

Q_DECLARE_METATYPE(StMorceau)
Q_DECLARE_METATYPE(ListeSample)
Q_DECLARE_METATYPE(ListePattern)

QDataStream& operator<<(QDataStream& out, const StMorceau& valeur);
QDataStream& operator<<(QDataStream& out, const StPosition& valeur);
QDataStream& operator<<(QDataStream& out, const StPattern& valeur);
QDataStream& operator<<(QDataStream& out, const StPiste& valeur);
QDataStream& operator<<(QDataStream& out, const StDivision& valeur);
QDataStream& operator<<(QDataStream& out, const StSample& valeur);
QDataStream& operator<<(QDataStream& out, const ListeSample& valeur);
QDataStream& operator<<(QDataStream& out, const ListePattern& valeur);

QDataStream& operator>>(QDataStream& in, StMorceau& valeur);
QDataStream& operator>>(QDataStream& in, StPosition& valeur);
QDataStream& operator>>(QDataStream& in, StPattern& valeur);
QDataStream& operator>>(QDataStream& in, StPiste& valeur);
QDataStream& operator>>(QDataStream& in, StDivision& valeur);
QDataStream& operator>>(QDataStream& in, StSample& valeur);
QDataStream& operator>>(QDataStream& in, ListeSample& valeur);
QDataStream& operator>>(QDataStream& in, ListePattern& valeur);

#endif // IOFILE_H
