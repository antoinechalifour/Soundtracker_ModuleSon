#ifndef MENUPANELIHM_H
#define MENUPANELIHM_H

#include "StDebug.h"

class IHMMenuPanel : public QWidget
{
    Q_OBJECT
private:
    QPushButton*  LoadSongButton;
    QPushButton*  LoadSampleButton;
    QPushButton*  SaveSongButton;
    QPushButton*  NewSongButton;
    QVBoxLayout* boxMenu;

public:
    explicit IHMMenuPanel(QWidget *parent = 0);
    QPushButton* getLoadSongButton();
signals:

public slots:

};

#endif // MENUPANELIHM_H
