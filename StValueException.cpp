#include <string>
#include "StValueException.h"
#include "StException.h"

StValueException::StValueException() :
StException(){}

StValueException::StValueException(std::string msg) :
StException(msg){}