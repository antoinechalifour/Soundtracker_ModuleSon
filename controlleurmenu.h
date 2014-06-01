#ifndef CONTROLLEURMENU_H
#define CONTROLLEURMENU_H

#include "StDebug.h"
#include "StSample.h"
#include "StMorceau.h"
#include "IHMMainWindow.h"
#include "IHMMenuPanel.h"
#include "listesample.h"

class ControlleurMenu : public QObject
{
    Q_OBJECT
private:
    ListeSample* samples;
    StMorceau* modele;
    IHMMainWindow* panel;

public:
    explicit ControlleurMenu(ListeSample* samples, StMorceau* modele, IHMMainWindow* panel, QObject *parent = 0);

signals:

public slots:
    void loadSample();
    void loadSong();
    void saveSong();
    void newSong();

};

#endif // CONTROLLEURMENU_H
