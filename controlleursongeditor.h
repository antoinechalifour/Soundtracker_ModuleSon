#ifndef CONTROLLEURSONGEDITOR_H
#define CONTROLLEURSONGEDITOR_H

#include "StDebug.h"
#include "StMorceau.h"
#include "IHMSongEditorPanel.h"
#include "listepattern.h"

class ControlleurSongEditor : public QObject
{
    Q_OBJECT
private:
    StMorceau* modele;
    ListePattern* patterns;
    IHMSongEditorPanel* panel;

public:
    explicit ControlleurSongEditor(StMorceau* modele, ListePattern* patterns, IHMSongEditorPanel* panel, QObject *parent = 0);

signals:

public slots:
    void play();
    void stop();
    void changerPattern(int value);
    void changerTempo(int value);
    void changerVolume(int value);
    void updatePosition();

};

#endif // CONTROLLEURSONGEDITOR_H
