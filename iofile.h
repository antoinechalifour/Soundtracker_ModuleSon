#ifndef IOFILE_H
#define IOFILE_H

#include "StDebug.h"
#include "StMorceau.h"
#include "StPosition.h"
#include "StPattern.h"
#include "StPiste.h"
#include "StDivision.h"
#include "StSample.h"

class IOFile
{
public:
    IOFile();
    void serialize(StMorceau* morceau);
    StMorceau* unserialize(QString fileName);
};

Q_DECLARE_METATYPE(StMorceau)
Q_DECLARE_METATYPE(StPosition)
Q_DECLARE_METATYPE(StPattern)
Q_DECLARE_METATYPE(StPiste)
Q_DECLARE_METATYPE(StDivision)
Q_DECLARE_METATYPE(StSample)

QDataStream& operator<<(QDataStream& out, const StMorceau& valeur);
QDataStream& operator<<(QDataStream& out, const StPosition& valeur);
QDataStream& operator<<(QDataStream& out, const StPattern& valeur);
QDataStream& operator<<(QDataStream& out, const StPiste& valeur);
QDataStream& operator<<(QDataStream& out, const StDivision& valeur);
QDataStream& operator<<(QDataStream& out, const StSample& valeur);

QDataStream& operator>>(QDataStream& in, StMorceau& valeur);
QDataStream& operator>>(QDataStream& in, StPosition& valeur);
QDataStream& operator>>(QDataStream& in, StPattern& valeur);
QDataStream& operator>>(QDataStream& in, StPiste& valeur);
QDataStream& operator>>(QDataStream& in, StDivision& valeur);
QDataStream& operator>>(QDataStream& in, StSample& valeur);

#endif // IOFILE_H
