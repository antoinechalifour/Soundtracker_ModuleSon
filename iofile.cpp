#include "iofile.h"

IOFile::IOFile(StMorceau* morceau, ListePattern* patterns, ListeSample* samples):
    morceau(morceau),
    patterns(patterns),
    samples(samples)
{
    qRegisterMetaTypeStreamOperators<StMorceau>("StMorceau");
    qRegisterMetaTypeStreamOperators<StPosition>("StPosition");
    qRegisterMetaTypeStreamOperators<StPattern>("StPattern");
    qRegisterMetaTypeStreamOperators<StPiste>("StPiste");
    qRegisterMetaTypeStreamOperators<StDivision>("StDivision");
    qRegisterMetaTypeStreamOperators<StSample>("StSample");
    qRegisterMetaTypeStreamOperators<ListeSample>("ListeSample");
    qRegisterMetaTypeStreamOperators<ListePattern>("ListePattern");

    QMetaTypeId<StMorceau>();
    QMetaTypeId<StPosition>();
    QMetaTypeId<StPattern>();
    QMetaTypeId<StPiste>();
    QMetaTypeId<StDivision>();
    QMetaTypeId<StSample>();
    QMetaTypeId<ListePattern>();
    QMetaTypeId<ListeSample>();
}

void IOFile::serialize(){
    QString fileName = morceau->getNom();
    QSettings ecriture(fileName, QSettings::IniFormat);
    /*
     * Ici on utilise les opérateurs<< qui s'appellent succesivement
     */
#ifdef STDEBUG
    cout<<"IOFile::serialize() - ListeSample"<<endl;
#endif
    ecriture.setValue("ListeSample", qVariantFromValue(*samples));

#ifdef STDEBUG
    cout<<"IOFile::serialize() - ListePattern"<<endl;
#endif
    ecriture.setValue("ListePattern", qVariantFromValue(*patterns));

#ifdef STDEBUG
    cout<<"IOFile::serialize() - StMorceau"<<endl;
#endif
    ecriture.setValue("StMorceau", qVariantFromValue(*morceau));
    ecriture.sync();
}

void IOFile::unserialize(QString fileName){
    /*
     * Analogue à la serialisation, mais on utilise les opérateurs>>
     */
    QSettings lecture(fileName, QSettings::IniFormat);
    *samples = lecture.value("ListeSample", qVariantFromValue(ListeSample())).value<ListeSample>();
    *patterns = lecture.value("ListePattern", qVariantFromValue(ListePattern())).value<ListePattern>();
    //*morceau = lecture.value("StMorceau", qVariantFromValue(StMorceau())).value<StMorceau>();
}

QDataStream& operator<<(QDataStream& out, const ListeSample& valeur){
    out << valeur.size();
    for(int i=0 ; i<valeur.size() ; i++){
        out << *(valeur.at(i));
    }

    return out;
}

QDataStream& operator<<(QDataStream& out, const ListePattern& valeur){
    out<< valeur.size();
    for(int i=0 ; i<valeur.size() ; i++){
        out << *(valeur.at(i));
    }

    return out;
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
        out<< valeur.getPosition(i) ;
    }

    return out;
}

QDataStream& operator<<(QDataStream& out, const StPosition& valeur){
    /*
     * On récupère le pattern stocké dans le pointeur et on le sauvegarde.
     * Appelle operator(datastream, pattern)
     */

    out<< valeur.getId();
    if(valeur.getPattern()==NULL) out<< -1;
    else{
        StPattern* pat = valeur.getPattern();
        out<<pat->getID();
    }

    return out;
}

QDataStream& operator<<(QDataStream& out, const StPattern& valeur){
    out<<valeur.getID()
         <<valeur.getNom();
    /*
     * On enregistre ensuite les pistes du pattern
     * Ici, ça appelle operator<<(datastream, piste)
     */
    for(int i=0 ; i <8 ; i++){
        out<<valeur.getPiste(i);
    }
    return out;
}

QDataStream& operator<<(QDataStream& out, const StPiste& valeur){
    out<<valeur.getId()
         <<valeur.isMute()
           <<valeur.isSolo();
    /*
     * On enregistre ensuite les divisions de la piste
     * Ici, ça appelle operator<<(datastream, division)
     */
    for(int i=0 ; i <64 ; i++){
        out<< valeur.getDivision(i);
    }
    return out;
}

QDataStream& operator<<(QDataStream& out, const StDivision& valeur){
    out<<valeur.getId()
        <<valeur.getNote()
          <<valeur.getVolume();
    if(valeur.getSample() == NULL) out<< -1;
    else {
        StSample sample=*(valeur.getSample());
        out<<sample.getId();
    }

    return out;
}

QDataStream& operator<<(QDataStream& out, const StSample& valeur){
    out<<valeur.getId()
         <<valeur.getNom()
           <<valeur.getVolume()
             <<valeur.isRepeat()
               <<valeur.getRepeatlen()
                 <<valeur.getPitch();
    return out;
}

QDataStream& operator>>(QDataStream& in, StMorceau& valeur){
    QString nom;
    int tempo;
    int volume;

    in >> nom;
    in >> tempo;
    in >> volume;

    valeur.setNom(nom);
    valeur.setTempo(tempo);
    valeur.setVolume(volume);

    for(int i=0 ; i<128 ; i++){
        in >> valeur.getPosition(i);
    }
    return in;
}

QDataStream& operator>>(QDataStream& in, StPattern& valeur){
    QString nom;
    int idPiste;
    bool mutePiste;
    bool soloPiste;
    int idDiv;
    int noteDiv;
    int volumeDiv;
    int idSample;

    in >> nom;
    valeur.setNom(nom);
    for(int i=0 ; i<8 ; i++){
        in >> idPiste;
        in >> mutePiste;
        in >> soloPiste;

        valeur.getPiste(i).setId(idPiste);
        valeur.getPiste(i).setMute(mutePiste);
        valeur.getPiste(i).setSolo(soloPiste);
        for(int j=0 ; j<64 ; j++){
            in >> idDiv;
            in >> noteDiv;
            in >> volumeDiv;
            in >> idSample;
#ifdef STDEBUG
            cout<<"\t- idDiv= "<<idDiv<<endl;
            cout<<"\t- noteDiv= "<<noteDiv<<endl;
            cout<<"\t- volumeDiv= "<<volumeDiv<<endl;
            cout<<"\t- idSample= "<<idSample<<endl;
#endif
            valeur.getPiste(i).getDivision(j).setId(idDiv);
            valeur.getPiste(i).getDivision(j).setNote(noteDiv);
            valeur.getPiste(i).getDivision(j).setVolume(volumeDiv);
            if(idSample != -1){
#ifdef STDEBUG
                cout<<"Ici à compléter...."<<endl;
#endif
            }
        }
    }
    return in;
}


QDataStream& operator>>(QDataStream& in, StPiste& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StPosition& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StDivision& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, StSample& valeur){
    return in;
}

QDataStream& operator>>(QDataStream& in, ListeSample& valeur){
    int nbSample;
    int id;
    QString nom;
    int volume;
    bool repeat;
    int repeatLen;
    int pitch;
    in >> nbSample;

#ifdef STDEBUG
    cout<<"IOFile::operator>>() : sortie de la liste de Samples ("<<nbSample<<")"<<endl;
#endif

    for(int i=0 ; i< nbSample ; i++){
        in >> id;
        in >> nom;
        in >> volume;
        in >> repeat;
        in >> repeatLen;
        in >> pitch;
#ifdef STDEBUG
        cout<<"\t- id= "<<id<<endl;
        cout<<"\t- nom= "<<nom.toStdString()<<endl;
        cout<<"\t- volume= "<<volume<<endl;
        cout<<"\t- repeat= "<<repeat<<endl;
        cout<<"\t- repeatLen= "<<repeatLen<<endl;
        cout<<"\t- pitch= "<<pitch<<endl;
#endif

        StSample* tmp = new StSample;
        tmp->setId(id);
        tmp->setSound(nom);
        tmp->setVolume(volume);
        tmp->setRepeat(repeat);
        tmp->setRepeatlen(repeatLen);
        tmp->setPitch(pitch);
        valeur.push_back(tmp);
    }
    return in;
}

QDataStream& operator>>(QDataStream& in, ListePattern& valeur){
    int nbPattern;
    in >> nbPattern;

    for(int i=0 ; i<nbPattern ; i++){
#ifdef STDEBUG
        cout<<"Creation du pattern "<<i<<endl;
#endif
        StPattern tmp;
        in >> tmp;
        StPattern* pattern = new StPattern(tmp);
        valeur.push_back(pattern);
    }
    return in;
}
