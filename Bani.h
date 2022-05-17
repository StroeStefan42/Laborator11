#ifndef BANI_H
#define BANI_H

#include <string>
#include <ostream>

using namespace std;

class Bani {
protected:
	double valoare;
	double nrBani;
public:
	Bani();
	Bani(double valoare, double nrBani);
	Bani(const Bani& p);
	virtual ~Bani();

	double getValoare();
	void setValoare(double valoare);
	double getNrBani();
	void setNrBani(double nrBani);

	virtual Bani* clone();

	Bani& operator=(const Bani& p);
	bool operator==(const Bani& p);

	virtual string toString(bool forFile = false);
};

#endif
