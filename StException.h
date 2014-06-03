#ifndef _STEXCEPTIONH
#define _STEXCEPTIONH

#include "StDebug.h"

/**
 * @brief Classe mère des exceptions de Soundtracker.
 * @author Antoine
 */
class StException{
protected:
private:
    QString msg;

public:
    /**
     * @brief StException - Constructeur par defaut de l'exception.
     */
	StException();

    /**
     * @brief StException - Construit l'exception avec un message.
     * @param msg le message de l'exception.
     */
    StException(QString msg);

    /**
     * @brief getMsg - Retourne le message lié à l'exception.
     * @return le message
     */
    QString getMsg();
};

#endif
