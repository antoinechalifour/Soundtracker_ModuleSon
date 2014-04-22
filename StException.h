#pragma once
#include <string>

class StException{
protected:
private:
	std::string msg;

public:
	StException();
	StException(std::string);

	std::string getMsg();
};