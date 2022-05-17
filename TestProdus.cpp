#include "TestProdus.h"
#include <assert.h>
#include "Produs.h"
#include "Util.h"

void TestProdus::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNume();
	this->testSetNume();
	this->testGetPret();
	this->testSetPret();
	this->testGetCod();
	this->testSetCod();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestProdus::testImplicitConstructor()
{
	Produs p;
	assert(p.getNume().empty());
	assert(p.getPret() == 0);
}

void TestProdus::testConstructorWithParameters()
{
	Produs p(1, "banane", 3);
	assert(p.getCod() == 1);
	assert(p.getNume() == "banane");
	assert(p.getPret() == 3);
}

void TestProdus::testCopyConstructor()
{
	Produs p1(1, "banane", 3);
	Produs p2(p1);
	assert(p2.getCod() == p1.getCod());
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
}

void TestProdus::testClone()
{
	Produs p(1, "banane", 3);
	Produs* pClone = p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestProdus::testGetNume()
{
	Produs p(1, "banane", 3);
	assert(p.getNume() == "banane");
}

void TestProdus::testSetNume()
{
	Produs p;
	p.setNume("banane");
	assert(p.getNume() == "banane");
}

void TestProdus::testGetPret()
{
	Produs p(1, "banane", 3);
	assert(p.getPret() == 3);
}

void TestProdus::testSetPret()
{
	Produs p;
	p.setPret(3);
	assert(p.getPret() == 3);
}

void TestProdus::testGetCod()
{
	Produs p(1, "banane", 3);
	assert(p.getCod() == 1);
}

void TestProdus::testSetCod()
{
	Produs p;
	p.setCod(3);
	assert(p.getCod() == 3);
}

void TestProdus::testAssignmentOperator()
{
	Produs p1(1, "banane", 3);
	Produs p2;
	p2 = p1;
	assert(p2.getCod() == p1.getCod());
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
}

void TestProdus::testEqualityOperator()
{
	Produs p1(1, "banane", 3);
	Produs p2 = p1;
	assert(p1 == p2);
	p2.setNume("bruosa");
	assert(!(p1 == p2));
	p2.setNume(p1.getNume());
	assert(p1 == p2);
	p2.setPret(10);
	assert(!(p1 == p2));
	p2.setPret(p1.getPret());
	assert(p1 == p2);
}

void TestProdus::testToString()
{
	Produs p(1, "banane", 3);
	assert(p.toString() == "1 banane 3");
}
