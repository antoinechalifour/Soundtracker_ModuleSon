#ifndef CONTROLLEURPATTERNEDITOR_H
#define CONTROLLEURPATTERNEDITOR_H

#include "StDebug.h"
#include "StPattern.h"
#include "IHMPatternEditorPanel.h"

class ControlleurPatternEditor : public QObject
{
    Q_OBJECT
private:
    vector<StPattern*> patterns;
    IHMPatternEditorPanel* panel;
    StPattern* current;

public:
    explicit ControlleurPatternEditor(vector<StPattern*>, IHMPatternEditorPanel* panel, QObject *parent = 0);

signals:

public slots:
    void setPattern(int);

};

#endif // CONTROLLEURPATTERNEDITOR_H
