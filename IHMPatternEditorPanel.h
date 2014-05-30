#ifndef PATTERNEDITORPANELIHM_H
#define PATTERNEDITORPANELIHM_H

#include "StDebug.h"
#include "IHMPiste.h"

class IHMPatternEditorPanel : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* num;
    QHBoxLayout* boxPattern;
    IHMPiste* pistes[8];
public:
    explicit IHMPatternEditorPanel(QWidget *parent = 0);
    inline IHMPiste* getPiste(int index){ return pistes[index]; }

signals:

public slots:

};

#endif // PATTERNEDITORPANELIHM_H
