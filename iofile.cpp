#include "iofile.h"

IOFile::IOFile()
{
    qRegisterMetaTypeStreamOperators<StMorceau>("StMorceau");
    qRegisterMetaTypeStreamOperators<StPosition>("StPosition");
    qRegisterMetaTypeStreamOperators<StPattern>("StPattern");
    qRegisterMetaTypeStreamOperators<StPiste>("StPiste");
    qRegisterMetaTypeStreamOperators<StDivision>("StDivision");
    qRegisterMetaTypeStreamOperators<StSample>("StSample");

    QMetaTypeId<StMorceau>();
    QMetaTypeId<StPosition>();
    QMetaTypeId<StPattern>();
    QMetaTypeId<StPiste>();
    QMetaTypeId<StDivision>();
    QMetaTypeId<StSample>();
}

void IOFile::serialize(StMorceau *morceau){
    QString fileName = morceau->getNom();
    QSettings ecriture(fileName, QSettings::IniFormat);
    ecriture.setValue("StMorceau", qVariantFromValue(*morceau));
    ecriture.sync();
}

void IOFile::unserialize(QString fileName){
    //a toi de compléter
}

QDataStream& operator<<(QDataStream& out, const StMorceau& valeur){
    out << valeur.getNom()
           << valeur.getTempo()
              << valeur.getVolume();
/*
    for(int i=0 ; i <128 ; i++){
        out<< valeur.getPosition(i);
    }
    */
    return out;
}

QDataStream& operator<<(QDataStream& out, const StPosition& valeur){
    return out;
}

QDataStream& operator<<(QDataStream& out, const StPattern& valeur){
    return out;
}

QDataStream& operator<<(QDataStream& out, const StPiste& valeur){
    return out;
}

QDataStream& operator<<(QDataStream& out, const StDivision& valeur){
    return out;
}

QDataStream& operator<<(QDataStream& out, const StSample& valeur){
    return out;
}

QDataStream& operator>>(QDataStream& in, StMorceau& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StPosition& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StPattern& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StPiste& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StDivision& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StSample& valeur){
    return in;
}
