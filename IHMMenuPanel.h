#ifndef MENUPANELIHM_H
#define MENUPANELIHM_H

#include "StDebug.h"

class IHMMenuPanel : public QWidget
{
    Q_OBJECT
private:
    QPushButton*  loadSongButton;
    QPushButton*  loadSampleButton;
    QPushButton*  saveSongButton;
    QPushButton*  newSongButton;
    QVBoxLayout* boxMenu;

public:
    explicit IHMMenuPanel(QWidget *parent = 0);
    inline QPushButton* getLoadSongButton(){ return loadSongButton; }
    inline QPushButton* getLoadSampleButton(){ return loadSampleButton; }
    inline QPushButton* getSaveSongButton(){ return saveSongButton; }
    inline QPushButton* getNewSongButton(){ return newSongButton; }
signals:

public slots:

};

#endif // MENUPANELIHM_H
