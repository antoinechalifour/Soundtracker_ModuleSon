#include "IHMMenuPanel.h"


IHMMenuPanel::IHMMenuPanel(QWidget *parent) :
    QWidget(parent)
{
    LoadSongButton= new QPushButton("Load Song");
    LoadSampleButton= new QPushButton("Load Sample");
    SaveSongButton= new QPushButton("Save Song");
    NewSongButton= new QPushButton("New Song");

    boxMenu = new QVBoxLayout(parent);

    boxMenu->addWidget(LoadSongButton);
    boxMenu->addWidget(LoadSampleButton);
    boxMenu->addWidget(SaveSongButton);
    boxMenu->addWidget(NewSongButton);



    setLayout(boxMenu);

}

QPushButton* IHMMenuPanel::getLoadSongButton(){
    return LoadSongButton;
}
