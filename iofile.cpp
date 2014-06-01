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
    /*
     * Ici on utilise les opérateurs<< qui s'appellent succesivement
     */
    ecriture.setValue("StMorceau", qVariantFromValue(*morceau));
    ecriture.sync();
}

StMorceau* IOFile::unserialize(QString fileName){
    //a toi de compléter

    /*
     * Analogue, mais on utilise les opérateurs>>
     */
    return NULL;
}

QDataStream& operator<<(QDataStream& out, const StMorceau& valeur){
    /*
     * On enregistre les infos du morceau
     */
    out << valeur.getNom()
           << valeur.getTempo()
              << valeur.getVolume();

    /*
     * On enregistre ensuite les positions
     * Ici, ça appelle operator<<(datastream, position)
     */
    for(int i=0 ; i <128 ; i++){
        out<< valeur.getPosition(i);
    }

    return out;
}

QDataStream& operator<<(QDataStream& out, const StPosition& valeur){
    /*
     * On récupère le pattern stocké dans le pointeur et on le sauvegarde.
     * Appelle operator(datastream, pattern)
     */
    StPattern pat = *(valeur.getPattern());
    out<< valeur.getId()
          <<pat;
    return out;
}

QDataStream& operator<<(QDataStream& out, const StPattern& valeur){
    /* A toi de continuer Paulo !
     */
    out<<valeur.getID(); //etc....
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
