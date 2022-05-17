#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <ostream>

using namespace std;

class Produs {
protected:
	double cod;
	string nume;
	double pret;
public:
	Produs();
	Produs(double cod, string nume, double pret);
	Produs(const Produs& p);
	virtual ~Produs();

	double getCod();
	void setCod(double cod);
	string getNume();
	void setNume(string nume);
	double getPret();
	void setPret(double pret);

	virtual Produs* clone();

	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);

	virtual string toString(bool forFile = false);
};

#endif
