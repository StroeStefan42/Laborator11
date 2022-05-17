#ifndef TESTREPO_H
#define TESTREPO_H

#pragma once
#include "Produs.h"
#include <vector>

using namespace std;

class TestRepo {
private:
	vector<Produs*> produse;
	void testGetAll();
	void testGetSize();
	void testGet();
	void testFind();
	void testAddProdus();
	void testUpdateProdus();
	void testDeleteProdus();
public:
	TestRepo();
	~TestRepo();
	void testAll();
};

#endif