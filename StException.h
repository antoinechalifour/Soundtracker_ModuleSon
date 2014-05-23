#ifndef _STEXCEPTIONH
#define _STEXCEPTIONH

#include "StDebug.h"

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
