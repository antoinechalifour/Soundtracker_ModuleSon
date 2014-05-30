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
public:
    explicit IHMPatternEditorPanel(QWidget *parent = 0);

signals:

public slots:

};

#endif // PATTERNEDITORPANELIHM_H
