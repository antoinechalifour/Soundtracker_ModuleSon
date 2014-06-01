#ifndef _STNULLEXCEPTIONH
#define _STNULLEXCEPTIONH

#include "StDebug.h"
#include "StException.h"

/**
  Gère les Exceptions de type NULL.
 * @brief The StNullException class
 * @author Antoine
 */
class StNullException : public StException{
public:
	StNullException();
    StNullException(QString);
};

#endif
