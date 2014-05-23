#ifndef _STVALUEEXCEPTIONH
#define _STVALUEEXCEPTIONH

#include "StDebug.h"
#include "StException.h"

class StValueException : public StException{
public:
	StValueException();
    StValueException(QString);
};

#endif
