#include "Bani.h"
#include "Util.h"

/**
 * Constructor.
 *
 */
Bani::Bani()
{
	this->valoare = 0;
	this->nrBani = 0;
}

/**
 * Constructor cu parametrii.
 *
 * \param cod
 * \param nume
 * \param pret
 */
Bani::Bani(double valoare, double nrBani)
{
	this->valoare = valoare;
	this->nrBani = nrBani;
}

/**
 * Copy constructor.
 *
 * \param p
 */
Bani::Bani(const Bani& p)
{
	this->valoare = p.valoare;
	this->nrBani = p.nrBani;
}

/**
 * Deconstructor.
 *
 */
Bani::~Bani()
{
}

/**
 * getter cod.
 *
 *
 */
double Bani::getValoare()
{
	return this->valoare;
}

/**
 * setter cod.
 *
 * \param cod
 */
void Bani::setValoare(double valoare)
{
	this->valoare = valoare;
}


/**
 * getter pret.
 *
 * \return
 */
double Bani::getNrBani()
{
	return this->nrBani;
}

/**
 * setter pret.
 *
 * \param pret
 */
void Bani::setNrBani(double nrBani)
{
	this->nrBani = nrBani;
}

/**
 * Clona produs.
 *
 * \return
 */
Bani* Bani::clone()
{
	return new Bani(this->valoare, this->nrBani);
}

/**
 * Operator de copiere.
 *
 * \param p
 * \return
 */
Bani& Bani::operator=(const Bani& p)
{
	if (&p != this)
	{
		this->setValoare(p.valoare);
		this->setNrBani(p.nrBani);
	}
	return *this;
}

/**
 * Operator de egalitate.
 *
 * \param p
 * \return
 */
bool Bani::operator==(const Bani& p)
{
	return this->valoare == p.valoare && this->nrBani == p.nrBani;
}

/**
 * Transformare din double in string.
 *
 * \param forFile
 * \return
 */
string Bani::toString(bool forFile)
{
	return convertDoubleToString(this->valoare) + " " + convertDoubleToString(this->nrBani);
}