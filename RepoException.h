#ifndef REPOEXCEPTION_H
#define REPOEXCEPTION_H

#include <exception>

using namespace std;

class RepoException : public runtime_error {
private:
	const char* message;
public:
	RepoException(const char* msg) : runtime_error(msg), message(msg)
	{}

	const char* what()
	{
		return message;
	}
};


#endif