#pragma once
#include <string>
#include "StException.h"

class StValueException : public StException{
public:
	StValueException();
	StValueException(std::string);
};