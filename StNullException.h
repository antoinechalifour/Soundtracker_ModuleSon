#ifndef _STNULLEXCEPTIONH
#define _STNULLEXCEPTIONH

#include "StDebug.h"
#include "StException.h"

/**
 * @brief The StNullException class - Gère les Exceptions de type NULL.
 * @author Antoine
 */
class StNullException : public StException{
public:
    /**
     * @brief StNullException - Constructeur par défaut.
     */
	StNullException();

    /**
     * @brief StNullException - Construit avec le message.
     * @param msg le message lié à l'exception.
     */
    StNullException(QString msg);
};

#endif
