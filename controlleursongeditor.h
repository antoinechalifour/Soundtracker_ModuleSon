#ifndef CONTROLLEURSONGEDITOR_H
#define CONTROLLEURSONGEDITOR_H

#include "StDebug.h"
#include "StMorceau.h"
#include "IHMSongEditorPanel.h"

class ControlleurSongEditor : public QObject
{
    Q_OBJECT
private:
    StMorceau* modele;
    IHMSongEditorPanel* panel;

public:
    explicit ControlleurSongEditor(StMorceau* modele, IHMSongEditorPanel* panel, QObject *parent = 0);

signals:

public slots:
    void play();
    void stop();
    void changerPattern(int value);

};

#endif // CONTROLLEURSONGEDITOR_H
