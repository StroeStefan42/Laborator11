#ifndef TESTPRODUS_H
#define TESTPRODUS_H

#pragma once
class TestProdus {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetNume();
	void testSetNume();
	void testGetPret();
	void testSetPret();
	void testGetCod();
	void testSetCod();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testToString();
public:
	void testAll();
};

#endif