#include "listesample.h"

ListeSample::ListeSample(QObject *parent) :
    QObject(parent)
{}

void ListeSample::push_back(StSample* sample){
    liste.push_back(sample);
    changed();
}
