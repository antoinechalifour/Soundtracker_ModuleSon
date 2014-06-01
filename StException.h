#ifndef _STEXCEPTIONH
#define _STEXCEPTIONH

#include "StDebug.h"

/**
  Classe mère des exceptions de Soundtracker.
 * @brief The StException class
 * @author Antoine
 */
class StException{
protected:
private:
    QString msg;

public:
	StException();
    StException(QString);

    QString getMsg();
};

#endif
