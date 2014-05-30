#include "IHMPatternEditorPanel.h"


IHMPatternEditorPanel::IHMPatternEditorPanel(QWidget *parent) :
    QWidget(parent)
{
    boxPattern = new QHBoxLayout(parent);
    num = new QVBoxLayout();

    for (int i = 0;  i < 8; i++){

        boxPattern->addWidget(new IHMPiste(i+1));
    }

    setLayout(boxPattern);

}
