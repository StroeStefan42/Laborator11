#include "ServiceBani.h"
#include "RepoBaniException.h"
#include "ValidationBaniException.h"
#include <algorithm>

using namespace std;

/**
 * Constructor.
 *
 */
ServiceBani::ServiceBani()
{

}

/**
 * Constructor cu parametrii.
 *
 * \param repo
 */
ServiceBani::ServiceBani(RepoBani* repoBani)
{
	this->repoBani = repoBani;
}

/**
 * Deconstructor.
 *
 */
ServiceBani::~ServiceBani()
{
}

/**
 * Returneaza tot repositoryul.
 *
 * \return
 */
vector<Bani*> ServiceBani::getAllBani()
{
	return this->repoBani->getAllBani();
}

/**
 * Getter pentru marimea repositoryul.
 *
 * \return
 */
int ServiceBani::getSize()
{
	return this->repoBani->getSize();
}

/**
 * Adauga produs.
 *
 * \param cod
 * \param nume
 * \param pret
 * \return
 */
void ServiceBani::addBaniService(double valoare, double nrBani) throw(RepoBaniException, ValidationBaniException)
{
	Bani* pc = new Bani(valoare, nrBani);
	this->repoBani->addBani(pc);
}

/**
 * Modifica produs.
 *
 * \param cod
 * \param numeVechi
 * \param numeNou
 * \param pret
 * \return
 */
void ServiceBani::updateBaniService(double valoareVeche, double valoareNoua, double nrBani) //throw(RepoException, ValidationException)
{
	Bani* pvechi = new Bani(valoareVeche, 0);
	Bani* pNou = new Bani(valoareNoua, nrBani);
	this->repoBani->updateBani(pvechi, pNou);
}


/**
 * Sterge produs.
 *
 * \param cod
 */
void ServiceBani::deleteBaniService(double valoare)
{
	auto banuti = this->repoBani->getAllBani();
	for (int i = 0; i < this->repoBani->getSize(); i++)
	{
		if (banuti[i]->getValoare() == valoare)
		{
			this->repoBani->deleteBani(banuti[i]);
			return;
		}
	}
}

/**
 * Gaseste dupa cod.
 *
 * \param cod
 * \return
 */
Bani* ServiceBani::getByValue(double valoare)
{
	auto banuti = this->repoBani->getAllBani();
	for (int i = 0; i < this->repoBani->getSize(); i++)
	{
		if (banuti[i]->getValoare() == valoare)
		{
			return banuti[i];
		}
	}

}
/**
 * Setter pentru bani.
 *
 * \param m
 */
void ServiceBani::setCoins(map<double, double> m)
{
	this->coins = m;
}

/**
 * Getter pentru bani.
 *
 * \return
 */
map<double, double> ServiceBani::getCoins()
{
	return this->coins;
}

/**
 * Adauga bani.
 *
 * \param value
 * \param amount
 */
void ServiceBani::addCoins(double value, double amount)
{
	map<double, double>::iterator it;
	it = coins.find(value);
	if (it != coins.end())
		it->second += amount;
	else
		coins.insert(pair<double, double>(value, amount));
}

/**
 * Sterge banii.
 *
 * \param value
 * \param amount
 * \return
 */
int ServiceBani::removeCoins(double value, double amount)
{
	map<double, double>::iterator it;
	it = coins.find(value);
	if (it != coins.end())
	{
		if (it->second < amount)
			return 0;
		it->second -= amount;
	}
	return 0;
}

/**
 * Verifica daca sunt bani pentru rest.
 *
 * \param rest
 * \param values
 * \return
 */
bool ServiceBani::enoughMoneyToGive(double rest, map<double, double>& values)
{
	double coin, amount;
	int x;
	if (rest == 0)
		return true;
	map<double, double>::reverse_iterator it;
	for (it = this->coins.rbegin(); it != this->coins.rend(); it++)
	{
		coin = it->first;
		amount = it->second;
		if (coin <= rest)
		{
			x = rest / coin;
			if (x > amount)
				x = amount;
			values.insert(pair<double, double>(coin, x));
			rest -= coin * x;
		}
	}
	if (rest == 0)
		return true;
	else
	{
		values.clear();
		return false;
	}
}