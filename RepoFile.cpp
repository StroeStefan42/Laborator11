#include "RepoFile.h"
#include <fstream>
#include "ValidatorProdus.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"

/**
 * Constructor.
 * 
 * \param fileName
 */
RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
	this->loadFromFile();
}

/**
 * Deconstructor.
 * 
 */
RepoFile::~RepoFile()
{
}

/**
 * Numele fisierului.
 * 
 * \param fileName
 */
void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

/**
 * Adauga produs.
 * 
 * \param p
 */
void RepoFile::addProdus(Produs* p) throw(ValidationException)
{
	Repo::addProdus(p);
	this->saveToFile();
}

/**
 * Modifica produs.
 * 
 * \param pVechi
 * \param pNou
 * \return 
 */
void RepoFile::updateProdus(Produs* pVechi, Produs* pNou) throw(ValidationException)
{
	Repo::updateProdus(pVechi, pNou);
	this->saveToFile();
}

/**
 * Sterge produs.
 * 
 * \param p
 * \return 
 */
void RepoFile::deleteProdus(Produs* p) throw(ValidationException)
{
	Repo::deleteProdus(p);
	this->saveToFile();
}

/**
 * Incarca din fisier.
 * 
 */
void RepoFile::loadFromFile()
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
					double cod = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double pret = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					Produs* pd = new Produs(cod, nume, pret);
					this->validatorProdus.validate(pd);
					this->produse.push_back(pd);
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
void RepoFile::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Produs* produs : this->produse)
		{
			f << produs->toString(true) << endl;
		}
	}
}
