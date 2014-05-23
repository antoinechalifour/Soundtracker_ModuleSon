#include <QString>
#include "StValueException.h"
#include "StException.h"

StValueException::StValueException() :
StException(){}

StValueException::StValueException(QString msg) :
StException(msg){}
