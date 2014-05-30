#ifndef MAINWINDOWIHM_H
#define MAINWINDOWIHM_H

#include "StDebug.h"
#include "IHMMenuPanel.h"
#include "IHMSongEditorPanel.h"
#include "IHMSampleEditor.h"
#include "IHMPatternEditorPanel.h"


namespace Ui {
class MainWindow;
}

class IHMMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget* conteneur;
    IHMMenuPanel* menu;
    IHMSongEditorPanel* songEditor;
    IHMSampleEditor* sampleEditor;
    IHMPatternEditorPanel* patternEditor;
    QGridLayout* grille;
    QScrollArea* patternList;

    QHBoxLayout* songLayout;
    QGroupBox* songBox;

    QHBoxLayout* sampleLayout;
    QGroupBox* sampleBox;



public:
    explicit IHMMainWindow(QWidget *parent = 0);
    ~IHMMainWindow();
    inline IHMSongEditorPanel* getSongEditor(){ return songEditor; }
    inline IHMMenuPanel* getMenu(){ return menu; }
    inline IHMSampleEditor* getSampleEditor(){ return sampleEditor; }
    inline IHMPatternEditorPanel* getPatternEditor(){ return patternEditor; }

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOWIHM_H
