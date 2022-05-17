#include "Service.h"
#include "RepoException.h"
#include "ValidationException.h"
#include <algorithm>

using namespace std;

/**
 * Constructor.
 * 
 */
Service::Service()
{

}

/**
 * Constructor cu parametrii.
 * 
 * \param repo
 */
Service::Service(Repo* repo)
{
	this->repo = repo;
}

/**
 * Deconstructor.
 * 
 */
Service::~Service()
{
}

/**
 * Returneaza tot repositoryul.
 * 
 * \return 
 */
vector<Produs*> Service::getAll()
{
	return this->repo->getAll();
}

/**
 * Getter pentru marimea repositoryul.
 * 
 * \return 
 */
int Service::getSize()
{
	return this->repo->getSize();
}

/**
 * Adauga produs.
 * 
 * \param cod
 * \param nume
 * \param pret
 * \return 
 */
void Service::addProdusService(double cod, string nume, double pret) throw(RepoException, ValidationException)
{
	Produs* pd = new Produs(cod, nume, pret);
	this->repo->addProdus(pd);
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
void Service::updateProdusService(double cod, string numeVechi, string numeNou, double pret) throw(RepoException, ValidationException)
{
	Produs* pvechi = new Produs(0, numeVechi, 0);
	Produs* pNou = new Produs(cod, numeNou, pret);
	this->repo->updateProdus(pvechi, pNou);
}


/**
 * Sterge produs.
 * 
 * \param cod
 */
void Service::deleteProdusService(double cod)
{
	auto produse = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
	{
		if (produse[i]->getCod() == cod)
		{
			this->repo->deleteProdus(produse[i]);
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
Produs* Service::getByCode(double cod)
{
	auto produse = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
	{
		if (produse[i]->getCod() == cod)
		{
			return produse[i];
		}
	}

}
/**
 * Setter pentru bani.
 * 
 * \param m
 */
void Service::setCoins(map<double, double> m)
{
	this->coins = m;
}

/**
 * Getter pentru bani.
 * 
 * \return 
 */
map<double, double> Service::getCoins()
{
	return this->coins;
}

/**
 * Adauga bani.
 * 
 * \param value
 * \param amount
 */
void Service::addCoins(double value, double amount)
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
int Service::removeCoins(double value, double amount)
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
bool Service::enoughMoneyToGive(double rest, map<double, double>& values)
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