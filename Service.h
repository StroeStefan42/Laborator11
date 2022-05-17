#ifndef SERVICE_H
#define SERVICE_H

#include "Repo.h"
#include <map>
class Service {
private:
	Repo* repo;
	map<double, double> coins;
public:
	Service();
	Service(Repo* repo);
	~Service();

	vector<Produs*> getAll();

	int getSize();
	void addProdusService(double cod, string nume, double pret);
	void updateProdusService(double cod, string numeVechi, string numeNou, double pret);
	void deleteProdusService(double cod);

	void setCoins(map<double, double> m);
	map<double, double> getCoins();
	void addCoins(double value, double amount);
	int removeCoins(double value, double amount);
	bool enoughMoneyToGive(double rest, map<double, double>& values);
	Produs* getByCode(double cod);
	//Repo& getRepo();
};

#endif
