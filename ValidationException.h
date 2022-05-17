#ifndef VALIDATIONEXCEPTION_H
#define VALIDATIONEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ValidationException {
private:
	string message;
public:
	ValidationException(string msg) : message(msg)
	{}

	string toString()
	{
		return message;
	}
};

#endif
