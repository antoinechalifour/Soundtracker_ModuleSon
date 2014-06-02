#include "listepattern.h"

ListePattern::ListePattern(QObject *parent) :
    QObject(parent)
{}

ListePattern::ListePattern(const ListePattern &copie){
    for(int i=0 ; i<copie.size() ; i++){
        this->push_back(copie.at(i));
    }
}

ListePattern& ListePattern::operator=(const ListePattern& copie){
    for(int i=0 ; i<copie.size() ; i++){
        this->push_back(copie.at(i));
    }

    return *this;
}

void ListePattern::push_back(StPattern* pattern){
    liste.push_back(pattern);
    changed();
}
