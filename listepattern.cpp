#include "listepattern.h"

ListePattern::ListePattern(QObject *parent) :
    QObject(parent)
{
}

void ListePattern::push_back(StPattern* pattern){
    liste.push_back(pattern);
    changed();
}
