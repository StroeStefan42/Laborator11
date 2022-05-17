#ifndef VALIDATIONBANIEXCEPTION_H
#define VALIDATIONBANIEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ValidationBaniException {
private:
	string message;
public:
	ValidationBaniException(string msg) : message(msg)
	{}

	string toString()
	{
		return message;
	}
};

#endif
