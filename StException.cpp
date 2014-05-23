#include "StException.h"

StException::StException():
	msg("")
{};

StException::StException(QString msg){
	this->msg = msg;
}

QString StException::getMsg(){
	return msg;
}
