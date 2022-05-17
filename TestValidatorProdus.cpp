#include "TestValidatorProdus.h"
#include "ValidatorProdus.h"
#include "ValidationException.h"
#include <cassert>

void TestValidatorProdus::testValidatorProdus()
{
	ValidatorProdus val;
	Produs* p1 = new Produs(1, "ciocolata", 5);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	Produs* p2 = new Produs(2, "", 5);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Produs* p3 = new Produs(1, "abc_", 5);
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Produs* p4 = new Produs(5, "abc", -1);
	try
	{
		val.validate(p4);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Produs* p5 = new Produs(4, "abc", 0);
	try
	{
		val.validate(p5);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
}

TestValidatorProdus::TestValidatorProdus()
{
}

TestValidatorProdus::~TestValidatorProdus()
{
}

void TestValidatorProdus::testAll()
{
	this->testValidatorProdus();
}
