#ifndef REPOBANIEXCEPTION_H
#define REPOBANIEXCEPTION_H

#include <exception>

using namespace std;

class RepoBaniException : public runtime_error {
private:
	const char* message;
public:
	RepoBaniException(const char* msg) : runtime_error(msg), message(msg)
	{}

	const char* what()
	{
		return message;
	}
};

#endif
