#ifndef SERVICEBANI_H
#define SERVICEBANI_H

#include "RepoBani.h"
#include <map>
class ServiceBani {
private:
	RepoBani* repoBani;
	map<double, double> coins;
public:
	ServiceBani();
	ServiceBani(RepoBani* repoBani);
	~ServiceBani();

	vector<Bani*> getAllBani();

	int getSize();
	void addBaniService(double valoare, double nrBani);
	void updateBaniService(double valoareVeche, double valoareNoua, double nrBani);
	void deleteBaniService(double valoare);

	void setCoins(map<double, double> m);
	map<double, double> getCoins();
	void addCoins(double value, double amount);
	int removeCoins(double value, double amount);
	bool enoughMoneyToGive(double rest, map<double, double>& values);
	Bani* getByValue(double valoare);
	//Repo& getRepo();
};

#endif
