#include "listesample.h"

ListeSample::ListeSample(QObject *parent) :
    QObject(parent)
{}

ListeSample::ListeSample(const ListeSample &copie){
    for(int i=0 ; i<copie.size() ; i++){
        this->push_back(copie.at(i));
    }
}

ListeSample& ListeSample::operator=(const ListeSample& copie){
    for(int i=0 ; i<copie.size() ; i++){
        this->push_back(copie.at(i));
    }

    return *this;
}

void ListeSample::push_back(StSample* sample){
    liste.push_back(sample);
    changed();
}
