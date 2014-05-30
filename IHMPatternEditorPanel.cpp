#include "IHMPatternEditorPanel.h"


IHMPatternEditorPanel::IHMPatternEditorPanel(QWidget *parent) :
    QWidget(parent)
{
    boxPattern = new QHBoxLayout(parent);
    num = new QVBoxLayout();

    for (int i = 0;  i < 8; i++){
        pistes[i] = new IHMPiste(i+1);
        boxPattern->addWidget(pistes[i]);
    }

    setLayout(boxPattern);
}
