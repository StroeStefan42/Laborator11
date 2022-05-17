#ifndef REPOFILE_H
#define REPOFILE_H

#include "Repo.h"

class RepoFile : public Repo {
private:
	string fileName;
public:
	RepoFile(string fileName);
	~RepoFile();

	void setFileName(string fileName);

	void addProdus(Produs* p);
	void updateProdus(Produs* pVechi, Produs* pNou);
	void deleteProdus(Produs* p);

	void loadFromFile();
	void saveToFile();
};

#endif
