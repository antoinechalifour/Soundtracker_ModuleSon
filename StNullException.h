#ifndef _STNULLEXCEPTIONH
#define _STNULLEXCEPTIONH

#include "StDebug.h"
#include "StException.h"

class StNullException : public StException{
public:
	StNullException();
    StNullException(QString);
};

#endif
