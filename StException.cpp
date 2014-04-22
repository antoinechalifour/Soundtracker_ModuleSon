#include "StException.h"

StException::StException():
	msg("")
{};

StException::StException(std::string msg){
	this->msg = msg;
}

std::string StException::getMsg(){
	return msg;
}