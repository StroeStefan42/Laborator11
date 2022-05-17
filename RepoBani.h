#ifndef REPOBANI_H
#define REPOBANI_H

#include "Bani.h"
#include <vector>
#include "ValidatorBani.h"

class RepoBani {
protected:
	vector<Bani*> banuti;
	ValidatorBani validatorBani;
public:
	RepoBani();
	~RepoBani();

	vector<Bani*> getAllBani();
	int getSize();
	Bani* get(int index);
	int find(Bani* p);

	bool searchByValue(int valoare);
	Bani& findByValue(int valoare);

	virtual void addBani(Bani* p);
	virtual void updateBani(Bani* pVechi, Bani* pNou);
	virtual void deleteBani(Bani* p);

	void empty();
};

#endif
