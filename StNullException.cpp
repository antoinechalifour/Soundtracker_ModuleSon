#include <QString>
#include "StNullException.h"
#include "StException.h"

StNullException::StNullException() :
StException(){}

StNullException::StNullException(QString msg) :
StException(msg){}
