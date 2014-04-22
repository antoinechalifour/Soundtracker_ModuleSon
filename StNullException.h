#pragma once
#include <string>
#include "StException.h"

class StNullException : public StException{
public:
	StNullException();
	StNullException(std::string);
};