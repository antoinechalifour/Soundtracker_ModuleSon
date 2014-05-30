#include "controlleursampleeditor.h"

ControlleurSampleEditor::ControlleurSampleEditor(StSample* modele, IHMSampleEditor* panel, QObject *parent) :
    modele(modele),
    panel(panel),
    QObject(parent)
{
}
