#include <assert.h>
#include "TestRepoFile.h"
#include "Repo.h"
#include "Produs.h"
#include "RepoException.h"
#include "ReadFromFileException.h"


void TestRepoFile::testAddProdus()
{
	RepoFile repoFile = RepoFile(this->fileName);
	repoFile.setFileName(this->fileNameOut);
	Produs* p = new Produs(1, "briosa", 5);
	repoFile.addProdus(p);
	assert(repoFile.getSize() == this->produse.size() + 1);
	assert(*repoFile.get(repoFile.getSize() - 1) == *p);
	try {
		repoFile.addProdus(p);
	}
	catch (RepoException e) {}
	catch (...)
	{
		assert(false);
	}
}

void TestRepoFile::testUpdateProdus()
{
	RepoFile repoFile = RepoFile(this->fileName);
	repoFile.setFileName(this->fileNameOut);
	Produs* pNou = new Produs(1, "briosa", 5);
	Produs* pNou2 = new Produs(2, "napolitane", 10);
	repoFile.updateProdus(this->produse[1], pNou);
	assert(*repoFile.get(0) == *this->produse[0]);
	assert(*repoFile.get(1) == *pNou);
	try {
		repoFile.updateProdus(this->produse[1], pNou2);
	}
	catch (RepoException ex) {}
	catch (...)
	{
		assert(false);
	}
	assert(*repoFile.get(0) == *this->produse[0]);
	assert(*repoFile.get(1) == *pNou);
}

void TestRepoFile::testDeleteProdus()
{
	RepoFile repoFile = RepoFile(this->fileName);
	repoFile.setFileName(this->fileNameOut);
	repoFile.deleteProdus(this->produse[0]);
	assert(repoFile.getSize() == 1);
	assert(*repoFile.get(0) == *this->produse[1]);
	Produs* p = new Produs(1, "briosa", 5);
	try {
		repoFile.deleteProdus(p);
	}
	catch (RepoException e) {}
	catch (...)
	{
		assert(false);
	}
	assert(repoFile.getSize() == 1);
	assert(*repoFile.get(0) == *this->produse[1]);
}

void TestRepoFile::testLoadFromFile()
{
	RepoFile repoFile = RepoFile(this->fileName);
	assert(repoFile.getSize() == this->produse.size());
	for (int i = 0; i < this->produse.size(); i++)
	{
		assert(*repoFile.get(i) == *this->produse[i]);
	}

	repoFile.setFileName("fdsvgdbgfbfgbbgf.txt");
	try {
		repoFile.loadFromFile();
		assert(false);
	}
	catch (ReadFromFileException& e) {

	}
	catch (...) {
		assert(false);
	}

	repoFile.setFileName(this->fileNameInvalid);
	try {
		repoFile.loadFromFile();
		assert(false);
	}
	catch (ReadFromFileException& e) {

	}
	catch (...) {
		assert(false);
	}
}

void TestRepoFile::testSaveToFile()
{
	RepoFile repoFile = RepoFile(this->fileName);;
	repoFile.setFileName(this->fileNameOut);
	Produs* newProdus = new Produs(1, "napolitane", 5);
	repoFile.addProdus(newProdus);
	repoFile.saveToFile();
	repoFile.loadFromFile();
	assert(repoFile.getSize() == this->produse.size() + 1);
	vector<Produs*> produse = repoFile.getAll();
	for (int i = 0; i < repoFile.getSize() - 1; i++)
	{
		assert(*produse[i] == *this->produse[i]);
	}
	assert(*produse[produse.size() - 1] == *newProdus);
}

TestRepoFile::TestRepoFile()
{
	Produs* p1 = new Produs(1, "banane", 3);
	Produs* p2 = new Produs(2, "chipsuri", 5);
	this->produse.push_back(p1);
	this->produse.push_back(p2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testAddProdus();
	this->testUpdateProdus();
	this->testDeleteProdus();
	this->testLoadFromFile();
	this->testSaveToFile();
}
