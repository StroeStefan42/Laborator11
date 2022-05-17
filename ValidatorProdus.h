#ifndef VALIDATORPRODUS_H
#define VALIDATORPRODUS_H

#include "Produs.h"
using namespace std;

class ValidatorProdus {
public:
	ValidatorProdus();
	~ValidatorProdus();

	void validate(Produs* p);
};

#endif
