#include "TestService.h"
#include <assert.h>
#include "Service.h"
#include "RepoException.h"
#include <vector>
#include "Repo.h"

void TestService::testGetAll()
{
	Repo* repo = new Repo();
	Service serv(repo);

	Produs* p1 = new Produs(1, "masina", 25);
	Produs* p2 = new Produs(2, "casa", 10);
	serv.addProdusService(p1->getCod(), p1->getNume(), p1->getPret());
	serv.addProdusService(p2->getCod(), p2->getNume(), p2->getPret());
	vector<Produs*> produse = serv.getAll();
	assert(*produse[0] == *p1);
	assert(*produse[1] == *p2);
}

void TestService::testAddProdus()
{
	Repo* repo = new Repo();
	Service serv(repo);

	Produs* p1 = new Produs(1, "masina", 25);
	serv.addProdusService(p1->getCod(), p1->getNume(), p1->getPret());
	assert(*serv.getAll()[0] == *p1);
}

void TestService::testUpdateProdus()
{
	Repo* repo = new Repo();
	Service serv(repo);

	Produs* p1 = new Produs(1, "masina", 25);
	serv.addProdusService(p1->getCod(), p1->getNume(), p1->getPret());
	Produs* p2 = new Produs(2, "casa", 10);
	Produs* p3 = new Produs(3, "masa", 50);
	serv.updateProdusService(p2->getCod(), p1->getNume(), p2->getNume(), p2->getPret());
	assert(*serv.getAll()[0] == *p2);
	try {
		serv.updateProdusService(p2->getCod(), p3->getNume(), p2->getNume(), p2->getPret());
		assert(false);
	}
	catch (RepoException& e) {
	}
	catch (...) {
		assert(false);
	}
}

void TestService::testDeleteProdus()
{
	Repo* repo = new Repo();
	Service serv(repo);

	Produs* p1 = new Produs(1, "masina", 25);
	serv.addProdusService(p1->getCod(), p1->getNume(), p1->getPret());
	serv.deleteProdusService(1);
	vector<Produs*> produse = serv.getAll();
	assert(produse.size() == 0);
	serv.deleteProdusService(p1->getCod());
	produse = serv.getAll();
	assert(produse.size() == 0);
}


TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::testAll()
{
	this->testGetAll();
	this->testAddProdus();
	this->testUpdateProdus();
	this->testDeleteProdus();
}
