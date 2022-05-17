#include "Produs.h"
#include "Util.h"

/**
 * Constructor.
 * 
 */
Produs::Produs()
{
	this->cod = 0;
	this->nume = "";
	this->pret = 0;
}

/**
 * Constructor cu parametrii.
 * 
 * \param cod
 * \param nume
 * \param pret
 */
Produs::Produs(double cod, string nume, double pret)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}

/**
 * Copy constructor.
 * 
 * \param p
 */
Produs::Produs(const Produs& p)
{
	this->cod = p.cod;
	this->nume = p.nume;
	this->pret = p.pret;
}

/**
 * Deconstructor.
 * 
 */
Produs::~Produs()
{
}

/**
 * getter cod.
 * 
 * 
 */
double Produs::getCod()
{
	return this->cod;
}

/**
 * setter cod.
 * 
 * \param cod
 */
void Produs::setCod(double cod)
{
	this->cod = cod;
}

/**
 * getter nume.
 * 
 * \return 
 */
string Produs::getNume()
{
	return this->nume;
}

/**
 * setter nume.
 * 
 * \param nume
 */
void Produs::setNume(string nume)
{
	this->nume = nume;
}

/**
 * getter pret.
 * 
 * \return 
 */
double Produs::getPret()
{
	return this->pret;
}

/**
 * setter pret.
 * 
 * \param pret
 */
void Produs::setPret(double pret)
{
	this->pret = pret;
}

/**
 * Clona produs.
 * 
 * \return 
 */
Produs* Produs::clone()
{
	return new Produs(this->cod, this->nume, this->pret);
}

/**
 * Operator de copiere.
 * 
 * \param p
 * \return 
 */
Produs& Produs::operator=(const Produs& p)
{
	if (&p != this)
	{
		this->setCod(p.cod);
		this->setNume(p.nume);
		this->setPret(p.pret);
	}
	return *this;
}

/**
 * Operator de egalitate.
 * 
 * \param p
 * \return 
 */
bool Produs::operator==(const Produs& p)
{
	return this->cod == p.cod && this->nume == p.nume && this->pret == p.pret;
}

/**
 * Transformare din double in string.
 * 
 * \param forFile
 * \return 
 */
string Produs::toString(bool forFile)
{
	return convertDoubleToString(this->cod) + " " + this->nume + " " + convertDoubleToString(this->pret);
}