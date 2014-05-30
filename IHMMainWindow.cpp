#include "IHMMainWindow.h"
#include "ui_mainwindow.h"


IHMMainWindow::IHMMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    conteneur = new QWidget;
    // Declaration des Panels
    menu = new IHMMenuPanel();
    songEditor = new IHMSongEditorPanel();
    sampleEditor = new IHMSampleEditor();
    patternEditor = new IHMPatternEditorPanel();

    patternList = new QScrollArea();
    patternList->setWidget(patternEditor);




    //création GroupBox song
    songLayout = new QHBoxLayout();
    songLayout->addWidget(songEditor);
    songBox = new QGroupBox("Song Editor");
    songBox->setLayout(songLayout);
    songBox->setFixedWidth(250);

    //création GroupBox sample
    sampleLayout = new QHBoxLayout();
    sampleLayout->addWidget(sampleEditor);
    sampleBox = new QGroupBox("Sample Editor");
    sampleBox->setLayout(sampleLayout);
    sampleBox->setFixedWidth(250);



    //Ajout a la grille
    grille = new QGridLayout(parent);
    grille->addWidget(sampleBox,0,1);
    grille->addWidget(menu,0,2);
    grille->addWidget(patternList,1,0,1,4);
    grille->addWidget(songBox,0,0);

    conteneur->setLayout(grille);

    setCentralWidget(conteneur);
}

IHMMainWindow::~IHMMainWindow()
{
    delete ui;
}
