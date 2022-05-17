#ifndef REPOBANIFIlE_H
#define REPOBANIFIlE_H

#include "RepoBani.h"
using namespace std;

class RepoBaniFile : public RepoBani {
private:
	string fileName;
public:
	RepoBaniFile(string fileName);
	~RepoBaniFile();

	void setFileName(string fileName);

	void addBani(Bani* p);
	void updateBani(Bani* pVechi, Bani* pNou);
	void deleteBani(Bani* p);

	void loadFromFile();
	void saveToFile();
};

#endif
