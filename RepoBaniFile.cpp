#include "RepoBaniFile.h"
#include <fstream>
#include "ValidatorBani.h"
#include "ValidationBaniException.h"
#include "ReadFromFileException.h"

/**
 * Constructor.
 *
 * \param fileName
 */
RepoBaniFile::RepoBaniFile(string fileName)
{
	this->fileName = fileName;
	this->loadFromFile();
}

/**
 * Deconstructor.
 *
 */
RepoBaniFile::~RepoBaniFile()
{
}

/**
 * Numele fisierului.
 *
 * \param fileName
 */
void RepoBaniFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

/**
 * Adauga produs.
 *
 * \param p
 */
void RepoBaniFile::addBani(Bani* p)
{
	RepoBani::addBani(p);
	this->saveToFile();
}

/**
 * Modifica produs.
 *
 * \param pVechi
 * \param pNou
 * \return
 */
void RepoBaniFile::updateBani(Bani* pVechi, Bani* pNou) throw(ValidationBaniException)
{
	RepoBani::updateBani(pVechi, pNou);
	this->saveToFile();
}

/**
 * Sterge produs.
 *
 * \param p
 * \return
 */
void RepoBaniFile::deleteBani(Bani* p) throw(ValidationBaniException)
{
	RepoBani::deleteBani(p);
	this->saveToFile();
}

/**
 * Incarca din fisier.
 *
 */
void RepoBaniFile::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->empty();
		string linie;
		string delim = " ";

		//try {

		while (getline(f, linie))
		{
			int pos = linie.find(delim);
			double valoare = stod(linie.substr(0, pos));
			linie = linie.erase(0, pos + 1);

			pos = linie.find(delim);
			double nrBani = stod(linie.substr(0, pos));
			linie = linie.erase(0, pos + 1);

			Bani* pd = new Bani(valoare, nrBani);
			this->validatorBani.validate(pd);
			this->banuti.push_back(pd);
		}

		//}
		//catch (...)
		//{
			//throw ReadFromFileException("formatul datelor din fisier este invalid!");
		//}
		f.close();
	}
	else {
		throw ReadFromFileException("fisierul nu exista!");
	}
}

/**
 * Salveaza din fisier.
 *
 */
void RepoBaniFile::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Bani* Bani : this->banuti)
		{
			f << Bani->toString(true) << endl;
		}
	}
}