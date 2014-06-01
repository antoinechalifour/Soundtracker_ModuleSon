#ifndef _STVALUEEXCEPTIONH
#define _STVALUEEXCEPTIONH

#include "StDebug.h"
#include "StException.h"

/**
  Classe permettant de gérer les erreurs dues à des valeurs illégales.
 * @brief The StValueException class
 * @author Antoine
 */
class StValueException : public StException{
public:
	StValueException();
    StValueException(QString);
};

#endif
