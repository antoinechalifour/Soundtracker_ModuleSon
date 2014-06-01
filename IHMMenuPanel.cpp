#include "IHMMenuPanel.h"


IHMMenuPanel::IHMMenuPanel(QWidget *parent) :
    QWidget(parent)
{
    loadSongButton= new QPushButton("Load Song");
    loadSampleButton= new QPushButton("Load Sample");
    saveSongButton= new QPushButton("Save Song");
    newSongButton= new QPushButton("New Song");

    boxMenu = new QVBoxLayout(parent);

    boxMenu->addWidget(loadSongButton);
    boxMenu->addWidget(loadSampleButton);
    boxMenu->addWidget(saveSongButton);
    boxMenu->addWidget(newSongButton);

    setLayout(boxMenu);

}
