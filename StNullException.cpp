#include <string>
#include "StNullException.h"
#include "StException.h"

StNullException::StNullException() :
StException(){}

StNullException::StNullException(std::string msg) :
StException(msg){}