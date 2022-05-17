#ifndef REPO_H
#define REPO_H

#include "Produs.h"
#include <vector>
#include "ValidatorProdus.h"

class Repo {
protected:
	vector<Produs*> produse;
	ValidatorProdus validatorProdus;
public:
	Repo();
	~Repo();

	vector<Produs*> getAll();
	int getSize();
	Produs* get(int index);
	int find(Produs* p);

	bool searchByCode(int cod);
	Produs& findByCode(int cod);

	virtual void addProdus(Produs* p);
	virtual void updateProdus(Produs* pVechi, Produs* pNou);
	virtual void deleteProdus(Produs* p);

	void empty();
};

#endif
